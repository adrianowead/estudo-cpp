#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

map<char, bool> ja_chutou;
vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for (char letra : PALAVRA_SECRETA)
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
    for (char letra : PALAVRA_SECRETA)
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

int main()
{
    cout << "+-----------------------------+" << endl;
    cout << "| Bem-Vindo ao Jogo da Forca! |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << endl;

    while (nao_acertou() && nao_enforcou())
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

        for (char letra : PALAVRA_SECRETA)
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

        cout << endl;
        cout << "Seu chute:" << endl;
        char chute;
        cin >> chute;

        chute = toupper(chute);

        ja_chutou[chute] = true;

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

    cout << "Fim de jogo!" << endl;
    cout << endl;

    if(nao_acertou()) {
        cout << "Você perdeu! Tente novamente!" << endl;
        cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
    } else {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
    }
}