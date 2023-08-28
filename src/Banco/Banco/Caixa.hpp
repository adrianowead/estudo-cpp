#pragma once
#include "Funcionario.hpp"

namespace Banco {
	class Caixa final: public Funcionario
	{
	public:
		Caixa(std::string nome, Cpf cpf, double salario);
		double bonificacao() const;
	};
}

