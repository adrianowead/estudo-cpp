#pragma once
#include <string>

namespace Banco {
	struct Conta
	{
		std::string numero;
		std::string cpf;
		std::string nome;
		float saldo;

		void sacar(float valor);
		void depositar(float valor);
	};
}
