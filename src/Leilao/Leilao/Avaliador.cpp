#include "Avaliador.hpp"
#include <algorithm>

bool Avaliador::ordenaLances(const Lance& lance1, const Lance& lance2)
{
	return lance1.recuperaValor() > lance2.recuperaValor();
}

void Avaliador::avalia(Leilao leilao)
{
	std::vector<Lance> lances = leilao.recuperaLances();

	for (Lance lance : lances)
	{
		if (lance.recuperaValor() > this->maiorValor)
		{
			this->maiorValor = lance.recuperaValor();
		}
		
		if (lance.recuperaValor() < this->menorValor)
		{
			this->menorValor = lance.recuperaValor();
		}
	}

	std::sort(lances.begin(), lances.end(), Avaliador::ordenaLances);

	size_t tamanho = lances.size() > 3 ? 3 : lances.size();

	this->maiores3Lances = std::vector<Lance>(lances.begin(), lances.begin() + tamanho);
}

float Avaliador::recuperaMaiorValor() const
{
	return this->maiorValor;
}

float Avaliador::recuperaMenorValor() const
{
	return this->menorValor;
}

std::vector<Lance> Avaliador::get3MaioresLances() const
{
	return this->maiores3Lances;
}
