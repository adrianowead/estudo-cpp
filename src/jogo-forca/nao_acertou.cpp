#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> ja_chutou;

bool nao_acertou()
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