#pragma once
#include <iostream>

/// <summary>
/// Função de boas vindas ao jogo
/// 
/// A instrução inline dispensa a necessidade de arquivo próprio cpp, não há unidade de tradução e nem necessidade de link
/// </summary>
inline void bemVindo()
{
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << "| Bem-Vindo ao Jogo da Forca! |" << std::endl;
    std::cout << "+-----------------------------+" << std::endl;
    std::cout << std::endl;
}