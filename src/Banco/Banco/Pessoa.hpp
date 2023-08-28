#pragma once
#include <string>
#include "Cpf.hpp"

namespace Banco {
	class Pessoa
	{
	protected:
		std::string nome;
		Cpf cpf;

	public:
		Pessoa(std::string nome, Cpf cpf);

	private:
		void validarNome();
	};
}

