#include <string>
#include "Cpf.hpp"

namespace Banco {
	class Titular
	{
	private:
		std::string nome;
		Cpf cpf;

	public:
		Titular(std::string cpf, std::string nome);

		const std::string getNome();
		const std::string getCpf();

	private:
		void validaNomeTitular();
	};
}
