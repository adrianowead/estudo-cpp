#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"

namespace Banco {
	class Titular final: public Pessoa
	{
	public:
		Titular(Cpf cpf, std::string nome);
	};
}
