#pragma once
#include <iostream>
#include <string>
#include <map>

namespace Forca{
    void mostra_placeholders(const std::string& palavra_secreta, std::map<char, bool>& ja_chutou);
}