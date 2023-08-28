#include "Funcionario.hpp"

RH::Funcionario::Funcionario(std::string nome, Individuo::Cpf cpf, double salario):
	Pessoa(nome, cpf),
	salario(salario)
{
	//
}

std::string RH::Funcionario::getNome() const
{
	return this->nome;
}

std::string RH::Funcionario::getCpf() const
{
	return this->cpf.getCpf();
}

double RH::Funcionario::getSalario() const
{
	return this->salario;
}
