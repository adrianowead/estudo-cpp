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
	std::string nomeCompleto = "Adriano"; // Small String Optimization = SSO


	return 0;
}