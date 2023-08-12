#include "mostrar_chutes_errados.hpp"

void mostraChutesErrados(std::vector<char> chutes_errados)
{
    if (chutes_errados.size() > 0)
    {
        std::cout << "Chutes errados: ";

        for (char letra : chutes_errados)
        {
            std::cout << letra << " ";
        }

        std::cout << std::endl;
    }
}