#pragma once
#include "Cpf.hpp"
#include <string>
#include "Pessoa.hpp"
#include "DiaDaSeamana.hpp"

namespace RH {
	class Funcionario: public Individuo::Pessoa
	{
	private:
		double salario;
		// 0 = D, 1 = S, 2 = T, 3 = Q, etc...
		DiaDaSemana diaDoPagamento;

	public:
		Funcionario(std::string nome, Individuo::Cpf cpf, double salario, DiaDaSemana diaDoPagamento);

		std::string getNome() const;
		std::string getCpf() const;

		virtual double bonificacao() const = 0;

	protected:
		double getSalario() const;
	};
}

