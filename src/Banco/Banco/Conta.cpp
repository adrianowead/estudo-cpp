#include "Conta.hpp"
#include <iostream>

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

float Banco::Conta::getSaldo()
{
	return saldo;
}

std::string Banco::Conta::getNumero()
{
	return numeroConta;
}

std::string Banco::Conta::getCpf()
{
	return cpfTitular;
}

std::string Banco::Conta::getNome()
{
	return nomeTitular;
}

void Banco::Conta::setNumero(std::string numero)
{
	numeroConta = numero;
}

void Banco::Conta::setNome(std::string nome)
{
	nomeTitular = nome;
}

void Banco::Conta::setCpf(std::string cpf)
{
	cpfTitular = cpf;
}