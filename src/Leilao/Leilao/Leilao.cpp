#include "Leilao.hpp"

Leilao::Leilao(std::string descricao): descricao(descricao)
{
    
}

const std::vector<Lance>& Leilao::recuperaLances() const
{
    return lances;
}

void Leilao::recebeLance(const Lance& lance)
{
    if (this->ultimoUsuario() == lance.getNome())
    {
        return;
    }

    this->lances.push_back(lance);
}

std::string Leilao::ultimoUsuario() const
{
    if (this->lances.size() > 0)
    {
        return this->lances.back().getNome();
    }

    return;
}
