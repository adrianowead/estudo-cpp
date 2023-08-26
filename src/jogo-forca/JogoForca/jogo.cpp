#include <map>
#include <vector>
#include "bem_vindo.hpp"
#include "sorteia_palavra.hpp"
#include "nao_acertou.hpp"
#include "mostrar_chutes_errados.hpp"
#include "mostrar_placeholders.hpp"
#include "pede_chute.hpp"
#include "encerramento.hpp"

using namespace std;

static string palavra_secreta;

static map<char, bool> ja_chutou;
static vector<char> chutes_errados;

int main()
{
    bem_vindo();

    palavra_secreta = sorteia_palavra();

    while (nao_acertou(palavra_secreta, ja_chutou) && chutes_errados.size() < 5)
    {
        mostra_chutes_errados(chutes_errados);

        mostra_placeholders(palavra_secreta, ja_chutou);

        pede_chute(&ja_chutou, chutes_errados, palavra_secreta);
    }

    encerramento(palavra_secreta, ja_chutou);
}