#include <iostream>
#include <string>
#include "Conta.hpp"

using namespace std;

int main()
{
	Banco::Conta conta;

	conta.numero = "123456";
	conta.saldo = 0;
	conta.depositar(1000);

	conta.sacar(42);

	cout << "Saldo: " << conta.saldo << endl;

	return 0;
}