#include "Conta.hpp"
#include <iostream>

int Banco::Conta::numeroDeContas = 0; // contador global

Banco::Conta::Conta(std::string conta, Titular titular) :
	conta(conta),
	titular(titular),
	saldo(0),
	taxaDeSaque(0.05)
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

	float valorDoSaque = valor + (this->taxaDeSaque * valor);

	if (valorDoSaque > saldo) {
		std::cout << "Saldo insuficiente." << std::endl;
		return;
	}

	std::cout << "Taxa: " << this->taxaDeSaque << std::endl;

	saldo -= valorDoSaque;
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

int Banco::Conta::getTotalContas()
{
	return numeroDeContas;
}

void Banco::Conta::setTaxaDeSaque(float taxa)
{
	if (taxa <= 0) {
		std::cout << "A Taxa de saque deve ser superior a zero." << std::endl;
		return;
	}

	this->taxaDeSaque = taxa;
}