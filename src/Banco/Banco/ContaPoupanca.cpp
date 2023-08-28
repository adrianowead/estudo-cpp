#include <iostream>
#include "ContaPoupanca.hpp"

Banco::ContaPoupanca::ContaPoupanca(std::string conta, Titular titular):
	Conta(conta, titular)
{
	Conta::setTaxaDeSaque(0.03);
}

void Banco::ContaPoupanca::sacar(float valor)
{
	std::cout << "Sacando " << valor << ", de uma conta Poupan�a" << std::endl;

	// repassando para a implementa��o padr�o da classe pai
	Conta::sacar(valor);
}