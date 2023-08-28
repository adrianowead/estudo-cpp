#pragma once
#include <string>
#include "Conta.hpp"

namespace Banco {
	// classes finais não podem ser herdadas
	class ContaPoupanca final: public Conta
	{
	public:
		ContaPoupanca(std::string conta, Titular titular);
		void sacar(float valor) override; // override permite reescrita do método
	};
}
