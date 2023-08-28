#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include "Autenticavel.hpp"

namespace Individuo {
	class Titular final: public Individuo::Pessoa, public Login::Autenticavel
	{
	public:
		Titular(Individuo::Cpf cpf, std::string nome, std::string senha);
	};
}
