#pragma once
#include <string>

namespace Banco {
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

