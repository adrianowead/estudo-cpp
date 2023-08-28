#include "Gerente.hpp"

Banco::Gerente::Gerente(std::string nome, Cpf cpf, double salario):
	Funcionario(nome, cpf, salario)
{
	//
}

double Banco::Gerente::bonificacao() const
{
	return this->getSalario() * 0.15;
}
