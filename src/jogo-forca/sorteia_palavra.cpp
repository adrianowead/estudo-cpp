#include "sorteia_palavra.hpp"
#include "ler_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra()
{
    std::vector<std::string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice_aleadorio = rand() % palavras.size();

    palavra_secreta = palavras[indice_aleadorio];
}