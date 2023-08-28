#include <iostream>
#include "ContaCorrente.hpp"

Banco::ContaCorrente::ContaCorrente(std::string conta, Titular titular) :
	Conta(conta, titular)
{
	Conta::setTaxaDeSaque(0.05);
}

void Banco::ContaCorrente::sacar(float valor)
{
	std::cout << "Sacando " << valor << ", de uma conta Corrente" << std::endl;

	// repassando para a implementação padrão da classe pai
	Conta::sacar(valor);
}