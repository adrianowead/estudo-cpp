#include "Conta.hpp"
#include <iostream>

Banco::Conta::Conta(std::string conta, std::string cpf, std::string titular)
{
	this->conta = conta;
	this->cpf = cpf;
	this->titular = titular;
	this->saldo = 0;
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

void Banco::Conta::setNumero(std::string numero)
{
	this->conta = numero;
}

void Banco::Conta::setNome(std::string nome)
{
	this->titular = nome;
}

void Banco::Conta::setCpf(std::string cpf)
{
	this->cpf = cpf;
}