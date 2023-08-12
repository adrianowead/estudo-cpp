#include "nao_enforcou.hpp"

bool nao_enforcou(std::vector<char> chutes_errados)
{
    return chutes_errados.size() < 5;
}