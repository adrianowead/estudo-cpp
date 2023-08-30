#include <iostream>
#include "ContaCorrente.hpp"

Banco::ContaCorrente::ContaCorrente(std::string conta, Individuo::Titular titular) :
	Conta(conta, titular)
{
	Conta::validarTaxaDeSaque();
}

std::pair<Banco::Conta::ResultadoSaque, double> Banco::ContaCorrente::sacar(const double valor)
{
	std::cout << "Sacando " << valor << ", de uma conta Corrente" << std::endl;

	// repassando para a implementação padrão da classe pai
	return Conta::sacar(valor);
}

double Banco::ContaCorrente::getTaxaDeSaque() const
{
	return 0.05;
}

void Banco::ContaCorrente::transferePara(Conta& destino, double valor)
{
	auto resultado = this->sacar(valor).first;
	
	if (resultado == Banco::Conta::ResultadoSaque::Sucesso) {
		destino.depositar(valor);
	}
	else {
		std::cout << "Falha ao mover fundos de uma conta para outra, verifique o saldo." << std::endl;
	}
}

// recebe todo o saldo da conta de origem
void Banco::ContaCorrente::operator+=(ContaCorrente& contaOrigem)
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
