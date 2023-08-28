#pragma once
#include <iostream>
#include <array>
#include <string>

namespace Forca{
    void chute_certo(char& chute, std::array<char, 5>* chutes_errados, std::string& palavra_secreta, int* contador_chutes_errados);
}