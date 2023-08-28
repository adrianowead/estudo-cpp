#pragma once
#include <string>
#include "Cpf.hpp"

namespace Banco {
	class Pessoa
	{
	private:
		std::string nome;
		Cpf cpf;

	public:
		Pessoa(std::string nome, Cpf cpf);
		const std::string getNome();
		const std::string getCpf();

	private:
		void validarNome();
	};
}

