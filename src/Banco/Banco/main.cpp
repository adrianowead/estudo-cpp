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

void fazLogin(Banco::Autenticavel& alguem, string senha)
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
		Banco::Titular(
			Banco::Cpf("123.456.789-10"), 
			"Adriano Maciel",
			"senha1"
		)
	);
	conta.depositar(1000);
	realizaSaque(conta, 10);

	cout << "Saldo (Poupança): " << conta.getSaldo() << endl;

	Banco::ContaCorrente conta2 = Banco::ContaCorrente(
		"22222",
		Banco::Titular(
			Banco::Cpf("134.444.5555-10"),
			"João B",
			"senha2"
		)
	);
	conta2.depositar(90);
	realizaSaque(conta2, 10);

	cout << "Saldo (Corrente): " << conta2.getSaldo() << endl;

	Banco::ContaCorrente conta3 = Banco::ContaCorrente("990",
		Banco::Titular(
			Banco::Cpf("555.222.111-00"), 
			"Ana P", 
			"senha3"
		)
	);

	conta2.transferePara(conta3, 10);

	cout << "Saldo (Corrente): " << conta2.getSaldo() << endl;
	cout << "Saldo (Conta Nova): " << conta3.getSaldo() << endl;

	cout << "Total de contas: " << Banco::Conta::getTotalContas() << endl;

	////

	Banco::Caixa caixa = Banco::Caixa(
		"Adriano",
		Banco::Cpf("000.111.222-00"),
		3200
	);

	cout << "Funcionário: " << caixa.getNome() << ", bônus: " << caixa.bonificacao() << endl;


	Banco::Gerente gerente = Banco::Gerente(
		"Ana S",
		Banco::Cpf("000.777.222-00"),
		13500,
		"senha4"
	);

	cout << "Funcionário: " << gerente.getNome() << ", bônus: " << gerente.bonificacao() << endl;

	fazLogin(gerente, "senha1");
	fazLogin(gerente, "senha4");

	return 0;
}