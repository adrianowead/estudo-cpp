#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
	Lance primeiroLance(Usuario("Adriano Maciel"), 1000);
	Lance segundoLance(Usuario("Vivian"), 2000);
	Lance terceiroLance(Usuario("Luiza"), 4010);
	Lance quartoLance(Usuario("Manoela"), 5300);

	Leilao leilao("Item X qualquer");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(terceiroLance);
	leilao.recebeLance(quartoLance);

	return leilao;
}

Leilao emOrdemDecrescente()
{
	Lance quartoLance(Usuario("Manoela"), 5300);
	Lance terceiroLance(Usuario("Luiza"), 4010);
	Lance segundoLance(Usuario("Vivian"), 2000);
	Lance primeiroLance(Usuario("Adriano Maciel"), 1000);

	Leilao leilao("Item X qualquer");
	leilao.recebeLance(quartoLance);
	leilao.recebeLance(terceiroLance);
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);
	
	return leilao;
}

TEST_CASE("Avaliador")
{
	// Arrange - Given
	Avaliador leiloeiro;

	SECTION("Leilões ordenados")
	{
		// Arrange - Given

		// generate roda o teste varias vezes, uma para cada conjunto de dados
		Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
		

		SECTION("Deve recuperar maior lance de leilão")
		{
			// Act - When
			leiloeiro.avalia(leilao);

			// Assert - Then
			float valorEsperado = 5300;

			REQUIRE(valorEsperado == leiloeiro.recuperaMaiorValor());
		}

		SECTION("Deve recuperar menor lance de leilão")
		{
			// Act - When
			leiloeiro.avalia(leilao);

			// Assert - Then
			float valorEsperado = 1000;

			REQUIRE(valorEsperado == leiloeiro.recuperaMenorValor());
		}
	}

	SECTION("Deve recuperar os 3 maiores lances")
	{
		// Arrange - Given
		Leilao leilao = emOrdemCrescente();

		// Act - When
		leiloeiro.avalia(leilao);

		// Assert - Then
		float valorEsperado = 3;
		std::vector<Lance> maiores3Lances = leiloeiro.get3MaioresLances();

		REQUIRE(valorEsperado == maiores3Lances.size());
		REQUIRE(5300 == maiores3Lances[0].recuperaValor());
		REQUIRE(4010 == maiores3Lances[1].recuperaValor());
		REQUIRE(2000 == maiores3Lances[2].recuperaValor());
	}
}

TEST_CASE("Leilão não deve receber testes consecutivos do mesmo usuário")
{
	// arrange
	Leilao leilao("Fiat 147 0km");

	Usuario adriano("Adriano");

	Lance primeiroLance(adriano, 1000);
	Lance segundoLance(adriano, 2000);

	// act
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	// assert
	REQUIRE(1 == leilao.recuperaLances().size());
	REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}