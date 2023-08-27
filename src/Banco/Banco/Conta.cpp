#include "Conta.hpp"
#include <iostream>

int Banco::Conta::numeroDeContas = 0; // contador global

Banco::Conta::Conta(std::string conta, std::string cpf, std::string titular) :
	conta(conta),
	cpf(cpf),
	titular(titular),
	saldo(0)
{
	// incrementar valor global
	numeroDeContas++;
}

Banco::Conta::~Conta()
{
	// decrementar ao destruir objeto de conta
	numeroDeContas--;
}

void Banco::Conta::sacar(float valor)
{
	if (valor < 1) {
		std::cout << "O valor a sacar deve ser igual ou maior do que 1.00." << std::endl;
		return;
	}

	if (valor > saldo) {
		std::cout << "Saldo insuficiente." << std::endl;
		return;
	}

	saldo -= valor;
}

void Banco::Conta::depositar(float valor)
{
	if (valor < 1) {
		std::cout << "O valor a ser depositado deve ser igual ou maior do que 1.00." << std::endl;
		return;
	}

	saldo += valor;
}

const float Banco::Conta::getSaldo()
{
	return saldo;
}

const std::string Banco::Conta::getNumero()
{
	return this->conta;
}

const std::string Banco::Conta::getCpf()
{
	return this->cpf;
}

const std::string Banco::Conta::getNome()
{
	return this->titular;
}

int Banco::Conta::getTotalContas()
{
	return numeroDeContas;
}