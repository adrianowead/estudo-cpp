#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "Cpf.hpp"

Individuo::Pessoa::Pessoa(std::string nome, Individuo::Cpf cpf):
	nome(nome),
	cpf(cpf)
{
	this->validarNome();
}

void Individuo::Pessoa::validarNome()
{
	if (this->nome.size() < 5) {
		std::cout << "Nome muito curto." << std::endl;
		exit(1);
	}
}
