#include "Funcionario.hpp"

Banco::Funcionario::Funcionario(std::string nome, Cpf cpf):
	Pessoa(nome, cpf),
	salario(0)
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