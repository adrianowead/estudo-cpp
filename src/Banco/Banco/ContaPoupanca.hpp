#pragma once
#include <string>
#include "Conta.hpp"

namespace Banco {
	// classes finais n�o podem ser herdadas
	class ContaPoupanca final: public Conta
	{
	public:
		ContaPoupanca(std::string conta, Titular titular);
		void sacar(double valor) override; // override permite reescrita do m�todo
		double getTaxaDeSaque() const override;
	};
}
