#include "Caixa.hpp"

Banco::Caixa::Caixa(std::string nome, Cpf cpf, double salario):
	Funcionario(nome, cpf, salario)
{
	//
}

double Banco::Caixa::bonificacao() const
{
	return this->getSalario() * 0.1;
}
