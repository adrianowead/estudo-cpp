#pragma once
#include "Leilao.hpp"

class Avaliador
{
private:
	float maiorValor;

public:
	void avalia(Leilao leilao);
	float recuperaMaiorValor() const;
};

