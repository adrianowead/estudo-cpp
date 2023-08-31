#include "Catch.hpp"
#include "Leilao.hpp"

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