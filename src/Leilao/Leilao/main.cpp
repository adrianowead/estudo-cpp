#include <iostream>
#include <string>
#include <string_view>

// sobrescrever o operador new
void* ::operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}

// continuação da dica 2
// para funções que só exibem strings, podemos passar na addinatura um string_view
// mesmo que seja uma literal
void ExibeTexto(std::string_view texto)
{
	std::cout << texto << std::endl;
}

int main()
{
	// 1ª dica: se não for necessário modificar, verificar tamanho
	// ou manipular a string, evite o uso da classe std::string
	// que por padrão aloca na heap

	// prefira ponteiro de caracteres (const char*)
	// mas com o cuidado de não ter um stack overflow, pois o espaço na stack é bem limitado ~2mb
	//std::string nomeCompleto = "Adriano Maciel da Silva"; // desperdício de memória
	//const char* nomeCompleto = "Adriano Maciel da Silva"; // otimizado

	// se de fato for necessário o uso da classe
	// mas a string é seguramente (e sabidamente) pequena o suficiente para alocação na stack
	// isso dependente muito da arquitetura (x64), compilador, etc...
	// std::string nomeCompleto = "Adriano"; // Small String Optimization = SSO





	// 2ª dica: manipulação de strings
	std::string frase = "A vingança nunca é plena, mata a alma e a envenena";

	// ao inves de copiar para uma nova alocação de memória parte da string
	// se o objetivo é apenas visualização, utilizar o string_view (C++17)
	// std::string parte1 = frase.substr(0, frase.find(',')); // desperdício
	// std::string parte2 = frase.substr(frase.find(',') + 1, frase.length()); // desperdício

	std::string_view parte1(frase.c_str(), frase.find(',')); // otimizado
	std::string_view parte2(frase.c_str() + frase.find(',') + 1, frase.length()); // otimizado

	// testando a dica de função otimizada
	ExibeTexto("Um texto qualquer literal, que não está na heap");


	return 0;
}