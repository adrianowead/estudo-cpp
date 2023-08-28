#include "Autenticavel.hpp"

Login::Autenticavel::Autenticavel(std::string senha):
	senha(senha)
{
	//
}

bool Login::Autenticavel::autentica(std::string senha) const
{
	return senha == this->senha;
}
