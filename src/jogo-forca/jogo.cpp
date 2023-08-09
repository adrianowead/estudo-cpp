#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta;

map<char, bool> ja_chutou;
vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for (char letra : palavra_secreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }

    return false;
}

bool nao_acertou()
{
    for (char letra : palavra_secreta)
    {
        if (!ja_chutou[letra])
        {
            return true;
        }
    }

    return false;
}

bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}

void bemVindo()
{
    cout << "+-----------------------------+" << endl;
    cout << "| Bem-Vindo ao Jogo da Forca! |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << endl;
}

void chuteCerto(char chute)
{
    if (letra_existe(chute))
    {
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }
    else
    {
        cout << "Você errou! Seu chute não está na palavra." << endl;

        chutes_errados.push_back(chute);
    }

    cout << endl;
}

void pedeChute()
{
    cout << endl;
    cout << "Seu chute:" << endl;
    char chute;
    cin >> chute;

    chute = toupper(chute);

    ja_chutou[chute] = true;

    chuteCerto(chute);
}

void mostraPlaceholders()
{
    for (char letra : palavra_secreta)
    {
        if (ja_chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
}

void mostraChutesErrados()
{
    if (chutes_errados.size() > 0)
    {
        cout << "Chutes errados: ";

        for (char letra : chutes_errados)
        {
            cout << letra << " ";
        }

        cout << endl;
    }
}

vector<string> ler_arquivo()
{
    vector<string> palavras_arquivo;

    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        if (quantidade_palavras > 0)
        {
            for (int i = 0; i < quantidade_palavras; i++)
            {
                string palavra_lida;
                arquivo >> palavra_lida;

                if (palavra_lida.length() > 1)
                {
                    palavras_arquivo.push_back(palavra_lida);
                }
            }
        }

        arquivo.close();

        if (palavras_arquivo.size() < 1)
        {
            cout << "Sem palavras no banco para sorteio." << endl;
            exit(2);
        }

        return palavras_arquivo;
    }
    else
    {
        cout << "Não foi possível acessar o banco de palavras!" << endl;
        exit(1);
    }
}

void salvarArquivo(vector<string> nova_lista)
{
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista)
        {
            arquivo << palavra << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "Não foi possível acessar o banco de palavras!" << endl;
        exit(1);
    }
}

void sorteia_palavra()
{
    vector<string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice_aleadorio = rand() % palavras.size();

    palavra_secreta = palavras[indice_aleadorio];
}

void adicionarPalavra()
{
    cout << "Digite a nova palavra, evite caracteres especiais:" << endl;

    string nova_palavra;
    cin >> nova_palavra;

    for (int i = 0; i < nova_palavra.size(); i++)
    {
        nova_palavra[i] = toupper(nova_palavra[i]);
    }

    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);

    salvarArquivo(lista_palavras);
}

void encerramento()
{
    cout << "Fim de jogo!" << endl;
    cout << endl;

    if (nao_acertou())
    {
        cout << "Você perdeu! Tente novamente!" << endl;
        cout << "A palavra secreta era: " << palavra_secreta << endl;
    }
    else
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma palavra nova ao banco? (S/N)" << endl;

        char resposta;
        cin >> resposta;
        resposta = toupper(resposta);

        if (resposta == 'S')
        {
            adicionarPalavra();
        }
    }
}

int main()
{
    bemVindo();

    sorteia_palavra();

    while (nao_acertou() && nao_enforcou())
    {
        mostraChutesErrados();

        mostraPlaceholders();

        pedeChute();
    }

    encerramento();
}