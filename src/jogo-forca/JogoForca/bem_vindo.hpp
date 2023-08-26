#pragma once
#include <iostream>

/// <summary>
/// Fun��o de boas vindas ao jogo
/// 
/// A instru��o inline dispensa a necessidade de arquivo pr�prio cpp, n�o h� unidade de tradu��o e nem necessidade de link
/// </summary>
inline void bem_vindo()
{
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << "| Bem-Vindo ao Jogo da Forca! |" << std::endl;
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << std::endl;
}