#include <iostream>
#include <string>
#include <string_view>

// sobrescrever o operador new
void* ::operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}

// continua��o da dica 2
// para fun��es que s� exibem strings, podemos passar na addinatura um string_view
// mesmo que seja uma literal
void ExibeTexto(std::string_view texto)
{
	std::cout << texto << std::endl;
}

int main()
{
	// 1� dica: se n�o for necess�rio modificar, verificar tamanho
	// ou manipular a string, evite o uso da classe std::string
	// que por padr�o aloca na heap

	// prefira ponteiro de caracteres (const char*)
	// mas com o cuidado de n�o ter um stack overflow, pois o espa�o na stack � bem limitado ~2mb
	//std::string nomeCompleto = "Adriano Maciel da Silva"; // desperd�cio de mem�ria
	//const char* nomeCompleto = "Adriano Maciel da Silva"; // otimizado

	// se de fato for necess�rio o uso da classe
	// mas a string � seguramente (e sabidamente) pequena o suficiente para aloca��o na stack
	// isso dependente muito da arquitetura (x64), compilador, etc...
	// std::string nomeCompleto = "Adriano"; // Small String Optimization = SSO





	// 2� dica: manipula��o de strings
	std::string frase = "A vingan�a nunca � plena, mata a alma e a envenena";

	// ao inves de copiar para uma nova aloca��o de mem�ria parte da string
	// se o objetivo � apenas visualiza��o, utilizar o string_view (C++17)
	// std::string parte1 = frase.substr(0, frase.find(',')); // desperd�cio
	// std::string parte2 = frase.substr(frase.find(',') + 1, frase.length()); // desperd�cio

	std::string_view parte1(frase.c_str(), frase.find(',')); // otimizado
	std::string_view parte2(frase.c_str() + frase.find(',') + 1, frase.length()); // otimizado

	// testando a dica de fun��o otimizada
	ExibeTexto("Um texto qualquer literal, que n�o est� na heap");


	return 0;
}