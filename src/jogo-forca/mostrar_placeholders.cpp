#include <iostream>
#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> ja_chutou;

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