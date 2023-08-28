#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include "Autenticavel.hpp"

namespace Banco {
	class Titular final: public Pessoa, public Autenticavel
	{
	public:
		Titular(Cpf cpf, std::string nome, std::string senha);
	};
}
