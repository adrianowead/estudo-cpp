#include "adicionar_palavra.hpp"
#include "ler_arquivo.hpp"
#include "salvar_arquivo.hpp"

void adicionarPalavra()
{
    std::cout << "Digite a nova palavra, evite caracteres especiais:" << std::endl;

    std::string nova_palavra;
    std::cin >> nova_palavra;

    for (int i = 0; i < nova_palavra.size(); i++)
    {
        nova_palavra[i] = toupper(nova_palavra[i]);
    }

    std::vector<std::string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);

    salvarArquivo(lista_palavras);
}