#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "Cpf.hpp"

Banco::Pessoa::Pessoa(std::string nome, Banco::Cpf cpf):
	nome(nome),
	cpf(cpf)
{
	this->validarNome();
}

void Banco::Pessoa::validarNome()
{
	if (this->nome.size() < 5) {
		std::cout << "Nome muito curto." << std::endl;
		exit(1);
	}
}

const std::string Banco::Pessoa::getNome()
{
	return this->nome;
}

const std::string Banco::Pessoa::getCpf()
{
	return this->cpf.getCpf();
}