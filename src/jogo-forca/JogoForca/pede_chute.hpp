#pragma once
#include <iostream>
#include <map>
#include <array>
#include <string>

namespace Forca{
    void pede_chute(std::map<char, bool>* ja_chutou, std::array<char, 5>& chutes_errados, std::string& palavra_secreta, int* contador_chutes_errados);
}