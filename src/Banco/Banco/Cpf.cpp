#include "Cpf.hpp"
#include <string>
#include <iostream>

Banco::Cpf::Cpf(std::string cpf):
	numero(cpf)
{
	this->validarCpf();
}

void Banco::Cpf::validarCpf()
{
	if (this->numero.size() < 11) {
		std::cout << "Comprimento de documento inválido." << std::endl;
		exit(1);
	}
}

const std::string Banco::Cpf::getCpf()
{
	return this->numero;
}