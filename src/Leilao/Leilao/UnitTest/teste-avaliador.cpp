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
