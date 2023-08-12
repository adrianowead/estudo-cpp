#include "sorteia_palavra.hpp"
#include "ler_arquivo.hpp"

std::string sorteia_palavra()
{
    std::vector<std::string> palavras = ler_arquivo();

    srand(time(NULL));
    int indice_aleadorio = rand() % palavras.size();

    return palavras[indice_aleadorio];
}