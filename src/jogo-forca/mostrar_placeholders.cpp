#include "mostrar_placeholders.hpp"

extern std::string palavra_secreta;
extern std::map<char, bool> ja_chutou;

void mostraPlaceholders()
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