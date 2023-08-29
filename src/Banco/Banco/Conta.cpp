#include "Conta.hpp"
#include <iostream>

int Banco::Conta::numeroDeContas = 0; // contador global

Banco::Conta::Conta(std::string conta, Individuo::Titular titular) :
	conta(conta),
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

// redefinindo o comportamento do operador += neste objeto
void Banco::Conta::operator+=(double valor)
{
	this->depositar(valor);
}

void Banco::Conta::sacar(double valor)
{
	if (valor < 1) {
		std::cout << "O valor a sacar deve ser igual ou maior do que 1.00." << std::endl;
		return;
	}

	double valorDoSaque = valor + (getTaxaDeSaque() * valor);

	if (valorDoSaque > this->saldo) {
		std::cout << "Saldo insuficiente." << std::endl;
		return;
	}

	std::cout << "Taxa: " << getTaxaDeSaque() << std::endl;

	this->saldo -= valorDoSaque;
}

void Banco::Conta::depositar(double valor)
{
	if (valor < 1) {
		std::cout << "O valor a ser depositado deve ser igual ou maior do que 1.00." << std::endl;
		return;
	}

	this->saldo += valor;
}

double Banco::Conta::getSaldo() const
{
	return this->saldo;
}

void Banco::Conta::validarTaxaDeSaque()
{
	if (getTaxaDeSaque() < 0) {
		std::cout << "A Taxa de saque não pode ser negativa." << std::endl;
		return;
	}
}

std::string Banco::Conta::getNumero() const
{
	return this->conta;
}

int Banco::Conta::getTotalContas()
{
	return numeroDeContas;
}
