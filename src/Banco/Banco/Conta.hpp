#pragma once
#include <string>
#include "Titular.hpp"

namespace Banco {
	class Conta
	{
	private:
		static int numeroDeContas; // global, independente da inst�ncia do objeto (static)

	public:
		static int getTotalContas();

	private:
		std::string conta;
		Titular titular;
		float saldo;

	public:
		// construtor
		Conta(std::string conta, Titular titular);

		// destrutor
		~Conta();

		void sacar(float valor);
		void depositar(float valor);

		const float getSaldo();
		const std::string getNumero();
		const std::string getCpf();
		const std::string getNome();
	};
}
