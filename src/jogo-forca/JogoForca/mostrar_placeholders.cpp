#include "mostrar_placeholders.hpp"

void Forca::mostra_placeholders(const std::string& palavra_secreta, std::map<char, bool>& ja_chutou)
{
    for (char letra : palavra_secreta)
    {
        if (ja_chutou[letra])
        {
            std::cout << letra << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
}