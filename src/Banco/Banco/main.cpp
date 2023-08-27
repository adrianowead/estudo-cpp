#include <iostream>
#include <string>
#include "Conta.hpp"

using namespace std;

int main()
{
	Banco::Conta conta = Banco::Conta("12345", "123.456.789-10", "Adriano Maciel");

	conta.depositar(1000);

	conta.sacar(42);

	cout << "Saldo: " << conta.getSaldo() << endl;

	return 0;
}