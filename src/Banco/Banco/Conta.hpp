#pragma once
#include <string>

namespace Banco {
	class Conta
	{
	private:
		static int numeroDeContas; // global, independente da inst�ncia do objeto (static)

	public:
		static int getTotalContas();

	private:
		std::string conta;
		std::string cpf;
		std::string titular;
		float saldo;

	public:
		// construtor
		Conta(std::string conta, std::string cpf, std::string titular);

		// destrutor
		~Conta();

		void sacar(float valor);
		void depositar(float valor);

		const float getSaldo();
		const std::string getNumero();
		const std::string getCpf();
		const std::string getNome();
	
	private:
		void validaNomeTitular();
	};
}
