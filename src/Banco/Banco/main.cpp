#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Funcionario.hpp"

using namespace std;

int main()
{
	Banco::Conta conta = Banco::Conta("12345", Banco::Titular(Banco::Cpf("123.456.789-10"), "Adriano Maciel"));
	conta.depositar(1000);
	conta.sacar(42);

	Banco::Conta conta2 = Banco::Conta("22222", Banco::Titular(Banco::Cpf("134.444.5555-10"), "João B"));
	conta2.depositar(93);
	conta2.sacar(42);

	cout << "Saldo (conta1): " << conta.getSaldo() << endl;
	cout << "Saldo (conta2): " << conta2.getSaldo() << endl;

	cout << "Total de contas: " << Banco::Conta::getTotalContas() << endl;

	////

	Banco::Funcionario funcionario = Banco::Funcionario(
		"Adriano",
		Banco::Cpf("000.111.222-00")
	);

	cout << "Funcionário: " << funcionario.getNome() << endl;

	return 0;
}