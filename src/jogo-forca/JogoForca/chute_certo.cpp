#include "chute_certo.hpp"
#include "letra_existe.hpp"

void  Forca::chute_certo(char& chute, std::array<char, 5>* chutes_errados, std::string& palavra_secreta, int* contador_chutes_errados)
{
    if ( Forca::letra_existe(chute, palavra_secreta))
    {
        std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
    }
    else
    {
        std::cout << "Você errou! Seu chute não está na palavra." << std::endl;

        (*chutes_errados)[*contador_chutes_errados] = chute;
        contador_chutes_errados++;
    }

    std::cout << std::endl;
}