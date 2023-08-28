#include "Funcionario.hpp"

Banco::Funcionario::Funcionario(std::string nome, Cpf cpf, double salario):
	Pessoa(nome, cpf),
	salario(salario)
{
	//
}

std::string Banco::Funcionario::getNome() const
{
	return this->nome;
}

std::string Banco::Funcionario::getCpf() const
{
	return this->cpf.getCpf();
}

double Banco::Funcionario::getSalario() const
{
	return this->salario;
}
