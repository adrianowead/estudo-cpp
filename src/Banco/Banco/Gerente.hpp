#pragma once
#include "Funcionario.hpp"
#include "Autenticavel.hpp"

namespace Banco {
	class Gerente final: public Funcionario, public Autenticavel
	{
	public:
		Gerente(std::string nome, Cpf cpf, double salario, std::string senha);
		double bonificacao() const;
	};
}

