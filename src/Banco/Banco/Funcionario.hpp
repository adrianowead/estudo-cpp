#pragma once
#include "Cpf.hpp"
#include <string>
#include "Pessoa.hpp"

namespace Banco {
	class Funcionario: public Pessoa
	{
	private:
		float salario;

	public:
		Funcionario(std::string nome, Cpf cpf);
	};
}

