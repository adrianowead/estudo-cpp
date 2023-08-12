#include "chute_certo.hpp"
#include "letra_existe.hpp"

void chuteCerto(char& chute, std::vector<char>* chutes_errados, std::string& palavra_secreta)
{
    if (letra_existe(chute, palavra_secreta))
    {
        std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
    }
    else
    {
        std::cout << "Você errou! Seu chute não está na palavra." << std::endl;

        chutes_errados->push_back(chute);
    }

    std::cout << std::endl;
}