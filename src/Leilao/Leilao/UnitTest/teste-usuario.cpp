#include "Catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usuário deve ter informado o seu primeiro nome e seu sobrenome")
{
	// arrange
	Usuario adriano("Adriano Maciel");

	// act
	std::string primeiroNome = adriano.getPrimeiroNome();
	std::string sobreNome = adriano.getSobreNome();

	// assert
	REQUIRE("Adriano" == primeiroNome);
	REQUIRE("Maciel" == sobreNome);
}