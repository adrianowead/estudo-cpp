#pragma once
#include "Funcionario.hpp"
#include "Cpf.hpp"

namespace RH {
	class Caixa final: public Funcionario
	{
	public:
		Caixa(std::string nome, Individuo::Cpf cpf, double salario, DiaDaSemana diaDoPagamento);
		double bonificacao() const;
	};
}

