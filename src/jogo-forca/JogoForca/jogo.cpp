#include <map>
#include <vector>
#include "bem_vindo.hpp"
#include "sorteia_palavra.hpp"
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "mostrar_chutes_errados.hpp"
#include "mostrar_placeholders.hpp"
#include "pede_chute.hpp"
#include "encerramento.hpp"

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