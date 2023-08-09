#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.cpp"
#include "nao_enforcou.cpp"
#include "bem_vindo.cpp"
#include "pede_chute.cpp"
#include "mostrar_placeholders.cpp"
#include "mostrar_chutes_errados.cpp"
#include "sorteia_palavra.cpp"
#include "encerramento.cpp"

using namespace std;

string palavra_secreta;

map<char, bool> ja_chutou;
vector<char> chutes_errados;

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