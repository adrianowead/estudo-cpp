#pragma once
#include <string>

namespace Individuo {
	class Cpf final
	{
	private:
		std::string numero;

		void validarCpf();

	public:
		Cpf(std::string cpf);
		std::string getCpf() const;
	};
}

