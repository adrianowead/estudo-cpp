#include "Funcionario.hpp"

Banco::Funcionario::Funcionario(std::string nome, Cpf cpf):
	Pessoa(nome, cpf),
	salario(0)
{
	//
}

const std::string Banco::Funcionario::getNome()
{
	return this->nome;
}

const std::string Banco::Funcionario::getCpf()
{
	return this->cpf.getCpf();
}