#include "Titular.hpp"
#include <iostream>

Individuo::Titular::Titular(Individuo::Cpf cpf, std::string nome, std::string senha):
	Pessoa(nome, cpf),
	Autenticavel(senha)
{
	//
}