#include "chute_certo.hpp"
#include "letra_existe.hpp"

extern std::vector<char> chutes_errados;

void chuteCerto(char chute)
{
    if (letra_existe(chute))
    {
        std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
    }
    else
    {
        std::cout << "Você errou! Seu chute não está na palavra." << std::endl;

        chutes_errados.push_back(chute);
    }

    std::cout << std::endl;
}