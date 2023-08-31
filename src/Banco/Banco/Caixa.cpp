#include "Caixa.hpp"

RH::Caixa::Caixa(std::string nome, Individuo::Cpf cpf, double salario, DiaDaSemana diaDoPagamento):
	Funcionario(nome, cpf, salario, diaDoPagamento)
{
	//
}

double RH::Caixa::bonificacao() const
{
	return this->getSalario() * 0.1;
}
