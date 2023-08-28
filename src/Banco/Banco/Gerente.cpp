#include "Gerente.hpp"

RH::Gerente::Gerente(std::string nome, Individuo::Cpf cpf, double salario, std::string senha):
	Funcionario(nome, cpf, salario),
	Autenticavel(senha)
{
	//
}

double RH::Gerente::bonificacao() const
{
	return this->getSalario() * 0.15;
}
