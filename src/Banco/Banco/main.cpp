#include <iostream>
#include <string>
#include "Conta.hpp"

using namespace std;

int main()
{
	Banco::Conta conta;

	conta.depositar(1000);

	conta.sacar(42);

	cout << "Saldo: " << conta.getSaldo() << endl;

	return 0;
}