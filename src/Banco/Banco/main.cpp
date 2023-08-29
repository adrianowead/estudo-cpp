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

int main()
{
	Banco::ContaPoupanca conta = Banco::ContaPoupanca(
		"12345",
		Individuo::Titular(
			Individuo::Cpf("123.456.789-10"),
			"Adriano Maciel",
			"senha1"
		)
	);
	conta.depositar(1000);
	realizaSaque(conta, 10);

	cout << "Saldo (Poupan�a): " << conta.getSaldo() << endl;

	Banco::ContaCorrente conta2 = Banco::ContaCorrente(
		"22222",
		Individuo::Titular(
			Individuo::Cpf("134.444.5555-10"),
			"Jo�o B",
			"senha2"
		)
	);

	// depositando atrav�s de operador
	conta2 += 90;

	realizaSaque(conta2, 10);

	cout << "Saldo (Corrente): " << conta2.getSaldo() << endl;

	Banco::ContaCorrente conta3 = Banco::ContaCorrente("990",
		Individuo::Titular(
			Individuo::Cpf("555.222.111-00"),
			"Ana P", 
			"senha3"
		)
	);

	conta2.transferePara(conta3, 10);

	cout << "Saldo (Corrente): " << conta2.getSaldo() << endl;
	cout << "Saldo (Conta Nova): " << conta3.getSaldo() << endl;

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