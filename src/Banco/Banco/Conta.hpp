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
		// é boa prática sempre marcar o destrutor como virtual
		// para que as classes filhas possam implementar seus destrutores
		// e isso garante a liberação de recursos
		// independentemente de ter sido alocado na heap ou não
		// evitando vazamento de memória
		virtual ~Conta();

		virtual void sacar(float valor); // virtual pode ser sobrescrito nas classes filhas
		void depositar(float valor);

		const float getSaldo();
		const std::string getNumero();

	protected:
		void setTaxaDeSaque(float taxa);
	};
}
