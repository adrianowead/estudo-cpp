#pragma once
#include <string>

namespace Banco {
	class Conta
	{
	private:
		std::string conta;
		std::string cpf;
		std::string titular;
		float saldo;

	public:
		Conta(std::string conta, std::string cpf, std::string titular);

		void sacar(float valor);
		void depositar(float valor);

		const float getSaldo();
		const std::string getNumero();
		const std::string getCpf();
		const std::string getNome();

		void setNumero(std::string numero);
		void setNome(std::string nome);
		void setCpf(std::string cpf);
	};
}
