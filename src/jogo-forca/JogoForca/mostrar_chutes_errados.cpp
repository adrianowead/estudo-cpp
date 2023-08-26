#include "mostrar_chutes_errados.hpp"

void Forca::mostra_chutes_errados(const std::vector<char>& chutes_errados)
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