#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> ler_arquivo()
{
    std::vector<std::string> palavras_arquivo;

    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        if (quantidade_palavras > 0)
        {
            for (int i = 0; i < quantidade_palavras; i++)
            {
                std::string palavra_lida;
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
            std::cout << "Sem palavras no banco para sorteio." << std::endl;
            exit(2);
        }

        return palavras_arquivo;
    }
    else
    {
        std::cout << "Não foi possível acessar o banco de palavras!" << std::endl;
        exit(1);
    }
}