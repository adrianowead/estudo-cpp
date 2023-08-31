#pragma once
#include "Leilao.hpp"

class Avaliador
{
private:
	float maiorValor = INT_MIN;
	float menorValor = INT_MAX;

public:
	void avalia(Leilao leilao);
	float recuperaMaiorValor() const;
	float recuperaMenorValor() const;
};

