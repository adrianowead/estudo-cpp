#pragma once
#include "Conta.hpp"

namespace Banco {
	class ContaCorrente final : public Conta
	{
	public:
		ContaCorrente(std::string conta, Individuo::Titular titular);
		std::pair<ResultadoSaque, double> sacar(const double valor) override;
		double getTaxaDeSaque() const override;
		void transferePara(Conta& destino, double valor);
		void operator += (ContaCorrente& contaOrigem);
	};
}

