#pragma once
#include <string>
#include <map>

namespace Forca{
    bool nao_acertou(const std::string& palavra_secreta, std::map<char, bool>& ja_chutou);
}