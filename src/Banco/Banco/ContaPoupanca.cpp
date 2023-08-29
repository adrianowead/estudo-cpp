#include <iostream>
#include "ContaPoupanca.hpp"

Banco::ContaPoupanca::ContaPoupanca(std::string conta, Individuo::Titular titular):
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

// recebe todo o saldo da conta de origem
void Banco::ContaPoupanca::operator+=(ContaPoupanca& contaOrigem)
{
	// definindo o valor da taxa de saque, para isentar o cliente da taxa
	double saldoAtual = contaOrigem.getSaldo();
	double custoTaxa = saldoAtual * contaOrigem.getTaxaDeSaque();

	// depositar a taxa
	contaOrigem.depositar(custoTaxa);

	// sacar tudo
	contaOrigem.sacar(saldoAtual);

	// creditar na conta atual
	this->depositar(saldoAtual);
}