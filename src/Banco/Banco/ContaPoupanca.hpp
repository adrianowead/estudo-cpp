#pragma once
#include <string>
#include "Conta.hpp"

namespace Banco {
	class ContaPoupanca: public Conta
	{
	public:
		ContaPoupanca(std::string conta, Titular titular);
		void sacar(float valor) override; // override permite reescrita do método
	};
}
