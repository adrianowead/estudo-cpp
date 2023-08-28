#include "Gerente.hpp"

Banco::Gerente::Gerente(std::string nome, Cpf cpf, double salario, std::string senha):
	Funcionario(nome, cpf, salario),
	Autenticavel(senha)
{
	//
}

double Banco::Gerente::bonificacao() const
{
	return this->getSalario() * 0.15;
}
