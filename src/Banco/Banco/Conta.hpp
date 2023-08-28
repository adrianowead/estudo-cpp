#pragma once
#include <string>
#include "Titular.hpp"

namespace Banco {
	class Conta
	{
	private:
		static int numeroDeContas; // global, independente da inst�ncia do objeto (static)
		float taxaDeSaque;

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

		virtual void sacar(float valor); // virtual pode ser sobrescrito nas classes filhas
		void depositar(float valor);

		const float getSaldo();
		const std::string getNumero();

	protected:
		void setTaxaDeSaque(float taxa);
	};
}
