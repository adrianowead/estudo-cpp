#include <iostream>
#include <string>
#include <string_view>
#include <memory>
#include <Usuario.hpp>

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

// teste de dia 3, compartilhando ponteiro
void ExibeNome(std::shared_ptr<Usuario> usuario)
{
	std::cout << usuario->recuperaNome() << std::endl;
}

int main2()
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




	// 3� dica: Quando necess�rio alocar objeto diretamente na heap
	// evitar o uso de new, e consequentemente evitar ter que usar o delete

	// Usuario* usuario = new Usuario("Adriano");
	// std::cout << usuario->recuperaNome() << std::endl;
	// delete usuario;

	// smart pointer
	std::unique_ptr<Usuario> usuario = std::make_unique<Usuario>("Adriano");

	std::cout << usuario->recuperaNome() << std::endl;

	// mas no caso acima, um unique_ptr n�o pode ser compatilhado
	// passado como refer�ncia ou algo assim
	// o c�digo abaixo daria erro
	// ExibeNome(usuario);

	// abaixo tem a abordagem de ponteiro que pode ser compartilhado
	// os argumentos s�o usados diretamente no construtor do tipo informado
	std::shared_ptr<Usuario> usuario2 = std::make_shared<Usuario>("Adriano");
	ExibeNome(usuario2);


	return 0;
}

class String
{
private:
	char* data;
	size_t size;
public:
	String(const char* string)
	{
		std::cout << "String criada" << std::endl;

		size = strlen(string);
		data = new char[size];
		memcpy(data, string, size);
	}

	// copy constructor
	String(const String& outraString)
	{
		std::cout << "String copiada" << std::endl;

		size = strlen(outraString.data);
		data = new char[size];
		memcpy(data, outraString.data, size);
	}

	// move constructor
	String(String&& outraString)
	{
		std::cout << "String movida" << std::endl;

		size = outraString.size;
		data = outraString.data;

		// invalidar a origem movida
		// evita erro ao destruir o objeto original referenciado
		outraString.size = 0;
		outraString.data = nullptr;
	}

	// destructor
	~String()
	{
		delete data;
	}
};

class User
{
private:
	String nome;
public:
	User(const String& nome) :
		nome(nome)
	{
		//
	}

	// r-value
	User(String&& nome) :
		nome((String&&) nome)
	{
		//
	}
};

int main()
{
	User(String("Adriano"));

	return 0;
}