#include "pede_chute.hpp"
#include "chute_certo.hpp"

void Forca::pede_chute(std::map<char, bool>* ja_chutou, std::array<char, 5>& chutes_errados, std::string& palavra_secreta, int* contador_chutes_errados)
{
    std::cout << std::endl;
    std::cout << "Seu chute:" << std::endl;
    char chute;
    std::cin >> chute;

    chute = toupper(chute);

    (*ja_chutou)[chute] = true;

    Forca::chute_certo(chute, &chutes_errados, palavra_secreta, contador_chutes_errados);
}