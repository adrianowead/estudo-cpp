#pragma once
#include "Cpf.hpp"
#include <string>
#include "Pessoa.hpp"

namespace RH {
	class Funcionario: public Individuo::Pessoa
	{
	private:
		double salario;

	public:
		Funcionario(std::string nome, Individuo::Cpf cpf, double salario);

		std::string getNome() const;
		std::string getCpf() const;

		virtual double bonificacao() const = 0;

	protected:
		double getSalario() const;
	};
}

