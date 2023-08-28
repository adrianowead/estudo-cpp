#pragma once
#include <string>
#include "Titular.hpp"

namespace Banco {
	class Conta
	{
	private:
		static int numeroDeContas; // global, independente da inst�ncia do objeto (static)

	public:
		static int getTotalContas();

	private:
		std::string conta;
		Individuo::Titular titular;
		double saldo;

	public:
		// construtor
		Conta(std::string conta, Individuo::Titular titular);

		// destrutor
		// é boa prática sempre marcar o destrutor como virtual
		// para que as classes filhas possam implementar seus destrutores
		// e isso garante a liberação de recursos
		// independentemente de ter sido alocado na heap ou não
		// evitando vazamento de memória
		virtual ~Conta();

		virtual void sacar(double valor); // virtual pode ser sobrescrito nas classes filhas
		void depositar(double valor);

		double getSaldo() const;
		std::string getNumero() const;

		// = 0 indica método puramente virtual,
		// sendo obrigatório nas classes filhas
		// e ao mesmo tempo torna a classe atual como asbtrada
		// não podendo ser instânciada diretamente
		// pois o método virtual não pode ser implementado na classe atual
		// e como é obrigatório a torna impossível de instanciar, por estar incompleta
		// é o mesmo que método abstrado em outras linguagens
		virtual double getTaxaDeSaque() const = 0;

	protected:
		void validarTaxaDeSaque();
	};
}
