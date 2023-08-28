#pragma once
#include "Funcionario.hpp"

namespace Banco {
	class Gerente final: public Funcionario
	{
	public:
		Gerente(std::string nome, Cpf cpf, double salario);
		double bonificacao() const;
	};
}

