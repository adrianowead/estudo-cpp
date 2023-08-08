#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    cout << "*************************************" << endl;
    cout << "* Bem-Vindos ao jogo da advinhação! *" << endl;
    cout << "*************************************" << endl;

    const int NUMERO_SECRETO = 42;

    int chute;
    cout << "Qual é o seu chute? " << endl;
    cin >> chute;

    cout << "O valor do seu chute é " << chute << endl;

    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    if(acertou) {
        cout << "Parabéns! Você acertou o número secreto!" << endl;
    } else if(maior) {
        cout << "Seu chute foi maior que o número secreto!" << endl;
    } else {
        cout << "Seu chute foi menor que o número secreto!" << endl;
    }
}
