#include "Caixa.hpp"

RH::Caixa::Caixa(std::string nome, Individuo::Cpf cpf, double salario):
	Funcionario(nome, cpf, salario)
{
	//
}

double RH::Caixa::bonificacao() const
{
	return this->getSalario() * 0.1;
}
