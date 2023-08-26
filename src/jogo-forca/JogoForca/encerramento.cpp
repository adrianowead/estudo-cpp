#include "encerramento.hpp"
#include "nao_acertou.hpp"
#include "adicionar_palavra.hpp"

void encerramento(std::string& palavra_secreta, std::map<char, bool>& ja_chutou)
{
    std::cout << "Fim de jogo!" << std::endl;
    std::cout << std::endl;

    if (nao_acertou(palavra_secreta, ja_chutou))
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
            adicionar_palavra();
        }
    }
}