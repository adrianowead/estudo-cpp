#include <iostream>
#include "ContaPoupanca.hpp"

Banco::ContaPoupanca::ContaPoupanca(std::string conta, Titular titular):
	Conta(conta, titular)
{
	Conta::validarTaxaDeSaque();
}

void Banco::ContaPoupanca::sacar(double valor)
{
	std::cout << "Sacando " << valor << ", de uma conta Poupança" << std::endl;

	// repassando para a implementação padrão da classe pai
	Conta::sacar(valor);
}

double Banco::ContaPoupanca::getTaxaDeSaque() const
{
	return 0.03;
}