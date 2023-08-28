#pragma once
#include <string>

namespace Banco {
	class Cpf
	{
	private:
		std::string numero;

		void validarCpf();

	public:
		Cpf(std::string cpf);
		const std::string getCpf();
	};
}

