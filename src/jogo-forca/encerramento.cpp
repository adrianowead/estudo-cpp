#include <iostream>
#include "nao_acertou.cpp"
#include "adicionar_palavra.cpp"

std::string palavra_secreta;

void encerramento()
{
    std::cout << "Fim de jogo!" << std::endl;
    std::cout << std::endl;

    if (nao_acertou())
    {
        std::cout << "Você perdeu! Tente novamente!" << std::endl;
        std::cout << "A palavra secreta era: " << palavra_secreta << std::endl;
    }
    else
    {
        std::cout << "Parabéns! Você acertou a palavra secreta!" << std::endl;

        std::cout << "Você deseja adicionar uma palavra nova ao banco? (S/N)" << std::endl;

        char resposta;
        std::cin >> resposta;
        resposta = toupper(resposta);

        if (resposta == 'S')
        {
            adicionarPalavra();
        }
    }
}