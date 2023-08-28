#pragma once
#include "Cpf.hpp"
#include <string>
#include "Pessoa.hpp"

namespace Banco {
	class Funcionario: public Pessoa
	{
	private:
		double salario;

	public:
		Funcionario(std::string nome, Cpf cpf, double salario);

		std::string getNome() const;
		std::string getCpf() const;

		virtual double bonificacao() const = 0;

	protected:
		double getSalario() const;
	};
}

