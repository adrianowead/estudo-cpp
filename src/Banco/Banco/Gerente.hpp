#pragma once
#include "Funcionario.hpp"
#include "Autenticavel.hpp"

namespace RH {
	class Gerente final: public Funcionario, public Login::Autenticavel
	{
	public:
		Gerente(std::string nome, Individuo::Cpf cpf, double salario, std::string senha);
		double bonificacao() const;
	};
}

