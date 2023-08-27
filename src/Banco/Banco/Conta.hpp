#pragma once
#include <string>

namespace Banco {
	class Conta
	{
	private:
		std::string numeroConta;
		std::string cpfTitular;
		std::string nomeTitular;
		float saldo = 0;

	public:
		void sacar(float valor);
		void depositar(float valor);

		float getSaldo();
		std::string getNumero();
		std::string getCpf();
		std::string getNome();

		void setNumero(std::string numero);
		void setNome(std::string nome);
		void setCpf(std::string cpf);
	};
}
