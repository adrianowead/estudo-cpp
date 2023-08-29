#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaPoupanca.hpp"
#include "ContaCorrente.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"
#include "Autenticavel.hpp"

using namespace std;

void realizaSaque(Banco::Conta& conta, float valor)
{
	conta.sacar(valor);
}

void fazLogin(const Login::Autenticavel& alguem, string senha)
{
	if (alguem.autentica(senha)) {
		cout << "Login com sucesso" << endl;
	}
	else {
		cout << "Falha de login" << endl;
	}
}

void testarOperatorEmOutroEscopo(Banco::Conta& conta)
{
	conta += 90;
}

int main()
{
	Banco::ContaPoupanca poupanca1 = Banco::ContaPoupanca(
		"12345",
		Individuo::Titular(
			Individuo::Cpf("123.456.789-10"),
			"Adriano Maciel",
			"senha1"
		)
	);
	poupanca1.depositar(1000);
	realizaSaque(poupanca1, 10);

	cout << "Saldo (poupanca1): " << poupanca1.getSaldo() << endl;

	Banco::ContaCorrente corrente1 = Banco::ContaCorrente(
		"22222",
		Individuo::Titular(
			Individuo::Cpf("134.444.5555-10"),
			"Jo�o B",
			"senha2"
		)
	);

	// depositando atrav�s de operador
	// observe que exatamente a mesma opera��o ser� feita na fun��o
	// testarOperatorEmOutroEscopo
	// e l�, n�o � necess�rio realizar convers�o, por estar em outro escopo
	// ent�o o conflito de overloading se d� no uso, e n�o na implementa��o
	// aparentemente
	(Banco::Conta&) corrente1 += 90;

	// repetindo a opera��o com operator
	// mas em outro escopo
	testarOperatorEmOutroEscopo(corrente1);

	realizaSaque(corrente1, 10);

	cout << "Saldo (corrente1): " << corrente1.getSaldo() << endl;

	Banco::ContaCorrente corrente2 = Banco::ContaCorrente("990",
		Individuo::Titular(
			Individuo::Cpf("555.222.111-00"),
			"Ana P", 
			"senha3"
		)
	);

	corrente1.transferePara(corrente2, 10);

	cout << "Saldo (corrente1): " << corrente1.getSaldo() << endl;
	cout << "Saldo (corrente2): " << corrente2.getSaldo() << endl;

	Banco::ContaCorrente corrente3 = Banco::ContaCorrente("991",
		Individuo::Titular(
			Individuo::Cpf("555.222.888-00"),
			"Beatriz H",
			"senha4"
		)
	);

	// a corrente3 ir� receber todo o saldo de corrente2
	// que por sua vez ser� zerado
	corrente3 += corrente2;

	cout << "Saldo (corrente2): " << corrente2.getSaldo() << endl;
	cout << "Saldo (corrente3): " << corrente3.getSaldo() << endl;

	Banco::ContaPoupanca poupanca2 = Banco::ContaPoupanca("991",
		Individuo::Titular(
			Individuo::Cpf("555.222.888-99"),
			"BJulia A",
			"senha5"
		)
	);

	// a poupanca2 ir� receber todo o saldo de poupanca1
	// que por sua vez ser� zerado
	poupanca2 += poupanca1;

	cout << "Saldo (poupanca1): " << poupanca1.getSaldo() << endl;
	cout << "Saldo (poupanca2): " << poupanca2.getSaldo() << endl;

	cout << "Total de contas: " << Banco::Conta::getTotalContas() << endl;

	////

	RH::Caixa caixa = RH::Caixa(
		"Adriano",
		Individuo::Cpf("000.111.222-00"),
		3200,
		DiaDaSemana::Terca
	);

	cout << "Funcion�rio: " << caixa.getNome() << ", b�nus: " << caixa.bonificacao() << endl;


	RH::Gerente gerente = RH::Gerente(
		"Ana S",
		Individuo::Cpf("000.777.222-00"),
		13500,
		DiaDaSemana::Sabado,
		"senha4"
	);

	cout << "Funcion�rio: " << gerente.getNome() << ", b�nus: " << gerente.bonificacao() << endl;

	fazLogin(gerente, "senha1");
	fazLogin(gerente, "senha4");

	return 0;
}