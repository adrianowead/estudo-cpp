#include "Autenticavel.hpp"

Banco::Autenticavel::Autenticavel(std::string senha):
	senha(senha)
{
	//
}

bool Banco::Autenticavel::autentica(std::string senha) const
{
	return senha == this->senha;
}
