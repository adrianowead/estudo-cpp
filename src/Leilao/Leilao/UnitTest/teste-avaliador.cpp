#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "Avaliador.hpp"

TEST_CASE("Deve recuperar maior lance de leilão em ordem crescente") {
	// Arrange - Given
	Lance primeiroLance(Usuario("Adriano Maciel"), 1000);
	Lance segundoLance(Usuario("Vivian"), 2000);

	Leilao leilao("Item X qualquer");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	Avaliador leiloeiro;

	// Act - When
	leiloeiro.avalia(leilao);

	// Assert - Then
	float valorEsperado = 2000;

	REQUIRE(valorEsperado == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão em ordem decrescente") {
	// Arrange - Given
	Lance primeiroLance(Usuario("Adriano Maciel"), 2000);
	Lance segundoLance(Usuario("Vivian"), 1000);

	Leilao leilao("Item X qualquer");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	Avaliador leiloeiro;

	// Act - When
	leiloeiro.avalia(leilao);

	// Assert - Then
	float valorEsperado = 1000;

	REQUIRE(valorEsperado == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os 3 maiores lances") {
	// Arrange - Given
	Lance primeiroLance(Usuario("Adriano Maciel"), 2000);
	Lance segundoLance(Usuario("Vivian"), 1000);
	Lance terceiroLance(Usuario("Luiza"), 4010);
	Lance quartoLance(Usuario("Manoela"), 5300);

	Leilao leilao("Item X qualquer");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(terceiroLance);
	leilao.recebeLance(quartoLance);

	Avaliador leiloeiro;

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
