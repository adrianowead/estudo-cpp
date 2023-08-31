#include "Cpf.hpp"
#include <string>
#include <iostream>

Individuo::Cpf::Cpf(std::string cpf):
	numero(cpf)
{
	this->validarCpf();
}

void Individuo::Cpf::validarCpf()
{
	if (this->numero.size() < 11) {
		std::cout << "Comprimento de documento inválido." << std::endl;
		exit(1);
	}
}

std::string Individuo::Cpf::getCpf() const
{
	return this->numero;
}