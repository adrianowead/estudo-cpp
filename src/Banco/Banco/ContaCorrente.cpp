#include <iostream>
#include "ContaCorrente.hpp"

Banco::ContaCorrente::ContaCorrente(std::string conta, Titular titular) :
	Conta(conta, titular)
{
	Conta::validarTaxaDeSaque();
}

void Banco::ContaCorrente::sacar(double valor)
{
	std::cout << "Sacando " << valor << ", de uma conta Corrente" << std::endl;

	// repassando para a implementação padrão da classe pai
	Conta::sacar(valor);
}

double Banco::ContaCorrente::getTaxaDeSaque() const
{
	return 0.05;
}

void Banco::ContaCorrente::transferePara(Conta& destino, double valor)
{
	this->sacar(valor);
	destino.depositar(valor);
}
