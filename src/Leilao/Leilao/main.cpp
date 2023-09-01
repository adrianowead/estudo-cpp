#include <iostream>
#include <string>

// sobrescrever o operador new
void* ::operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
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
	std::string nomeCompleto = "Adriano"; // Small String Optimization = SSO


	return 0;
}