#pragma once
#include "Conta.hpp"

namespace Banco {
	class ContaCorrente final : public Conta
	{
	public:
		ContaCorrente(std::string conta, Titular titular);
		void sacar(float valor) override;
	};
}

