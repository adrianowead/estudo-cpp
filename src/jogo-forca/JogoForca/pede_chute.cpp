#include "pede_chute.hpp"
#include "chute_certo.hpp"

void Forca::pede_chute(std::map<char, bool>* ja_chutou, std::vector<char>& chutes_errados, std::string& palavra_secreta)
{
    std::cout << std::endl;
    std::cout << "Seu chute:" << std::endl;
    char chute;
    std::cin >> chute;

    chute = toupper(chute);

    (*ja_chutou)[chute] = true;

    Forca::chute_certo(chute, &chutes_errados, palavra_secreta);
}