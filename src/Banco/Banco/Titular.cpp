#include "Titular.hpp"
#include <iostream>

Banco::Titular::Titular(Cpf cpf, std::string nome, std::string senha):
	Pessoa(nome, cpf),
	Autenticavel(senha)
{
	//
}