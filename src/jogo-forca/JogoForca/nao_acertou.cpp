#include "nao_acertou.hpp"

bool nao_acertou(const std::string& palavra_secreta, std::map<char, bool>& ja_chutou)
{
    for (char letra : palavra_secreta)
    {
        if (!ja_chutou[letra])
        {
            return true;
        }
    }

    return false;
}