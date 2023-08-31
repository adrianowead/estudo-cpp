#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao)
{
	std::vector<Lance> lances = leilao.recuperaLances();

	for (Lance lance : lances)
	{
		if (lance.recuperaValor() > this->maiorValor)
		{
			this->maiorValor = lance.recuperaValor();
		}
	}
}

float Avaliador::recuperaMaiorValor() const
{
	return this->maiorValor;
}
