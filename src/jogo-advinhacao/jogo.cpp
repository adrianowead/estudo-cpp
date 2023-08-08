#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    cout << "*************************************" << endl;
    cout << "* Bem-Vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;

    int numero_secreto = 42;

    int chute;
    cout << "Qual é o seu chute? " << endl;
    cin >> chute;

    cout << "O valor do seu chute é " << chute << endl;

    if(chute == numero_secreto) {
        cout << "Parabéns! Você acertou o número secreto!" << endl;
    } else if(chute > numero_secreto) {
        cout << "Seu chute foi maior que o número secreto!" << endl;
    } else {
        cout << "Seu chute foi menor que o número secreto!" << endl;
    }
}
