#include <iostream>
#include <map>
#include "chute_certo.cpp"

std::map<char, bool> ja_chutou;

void pedeChute()
{
    std::cout << std::endl;
    std::cout << "Seu chute:" << std::endl;
    char chute;
    std::cin >> chute;

    chute = toupper(chute);

    ja_chutou[chute] = true;

    chuteCerto(chute);
}