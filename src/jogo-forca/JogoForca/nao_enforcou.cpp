#include "nao_enforcou.hpp"

bool Forca::nao_enforcou(std::array<char, 5> chutes_errados)
{
    return chutes_errados.size() < 5;
}