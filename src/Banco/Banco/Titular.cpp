#include "Titular.hpp"
#include <iostream>

Banco::Titular::Titular(std::string cpf, std::string nome):
	nome(nome),
	cpf(cpf)
{
	this->validaNomeTitular();
}

const std::string Banco::Titular::getNome()
{
	return this->nome;
}

const std::string Banco::Titular::getCpf()
{
	return this->cpf;
}

void Banco::Titular::validaNomeTitular()
{
	if (this->nome.size() < 5) {
		std::cout << "Nome muito curto." << std::endl;
		exit(1);
	}
}