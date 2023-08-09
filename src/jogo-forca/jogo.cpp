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

int main()
{
    cout << "+-----------------------------+" << endl;
    cout << "| Bem-Vindo ao Jogo da Forca! |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou)
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
}