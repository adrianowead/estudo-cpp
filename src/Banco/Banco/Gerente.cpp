#include "Gerente.hpp"

RH::Gerente::Gerente(std::string nome, Individuo::Cpf cpf, double salario, DiaDaSemana diaDoPagamento, std::string senha):
	Funcionario(nome, cpf, salario, diaDoPagamento),
	Autenticavel(senha)
{
	//
}

double RH::Gerente::bonificacao() const
{
	return this->getSalario() * 0.15;
}
