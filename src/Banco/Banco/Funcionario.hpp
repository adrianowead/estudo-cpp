#pragma once
#include "Cpf.hpp"
#include <string>

namespace Banco {
	class Funcionario
	{
	private:
		std::string nome;
		Cpf cpf;
		float salario;

	public:
		Funcionario(std::string nome, Cpf cpf);
	};
}

