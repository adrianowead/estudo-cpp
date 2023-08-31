#include "Usuario.hpp"

Usuario::Usuario(std::string nome): nome(nome)
{
}

std::string Usuario::recuperaNome() const
{
    return nome;
}

std::string Usuario::getPrimeiroNome() const
{
    return this->nome.substr(0, this->nome.find(' '));
}

std::string Usuario::getSobreNome() const
{
    return this->nome.substr(this->nome.find(' ') + 1, this->nome.length());
}
