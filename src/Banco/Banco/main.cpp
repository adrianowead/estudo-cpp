#include <iostream>
#include <string>
#include "Conta.hpp"

using namespace std;

int main()
{
	Banco::Conta conta = Banco::Conta("12345", Banco::Titular("123.456.789-10", "Adriano Maciel"));
	conta.depositar(1000);
	conta.sacar(42);

	Banco::Conta conta2 = Banco::Conta("22222", Banco::Titular("134.444.5555-10", "João B"));
	conta2.depositar(93);
	conta2.sacar(42);

	cout << "Saldo (" << conta.getNome() << "): " << conta.getSaldo() << endl;
	cout << "Saldo (" << conta2.getNome() << "): " << conta2.getSaldo() << endl;

	cout << "Total de contas: " << Banco::Conta::getTotalContas() << endl;

	return 0;
}