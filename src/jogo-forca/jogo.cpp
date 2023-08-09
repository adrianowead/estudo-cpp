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
    }
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

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    for (int i = 0; i < quantidade_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;

        palavras_arquivo.push_back(palavra_lida);
    }

    return palavras_arquivo;
}

void sorteia_palavra()
{
    vector<string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice_aleadorio = rand() % (palavras.size() - 1);

    palavra_secreta = palavras[indice_aleadorio];
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