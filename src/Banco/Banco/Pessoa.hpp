#pragma once
#include <string>
#include "Cpf.hpp"

namespace Individuo {
	class Pessoa
	{
	protected:
		std::string nome;
		Individuo::Cpf cpf;

	public:
		Pessoa(std::string nome, Cpf cpf);
		std::string getNome() const;

	private:
		void validarNome();
	};
}

