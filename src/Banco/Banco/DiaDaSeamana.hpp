#pragma once

// o class define o escopo do enum para DiaDaSemana::<dia>
enum class DiaDaSemana : unsigned char // definindo que será apenas inteiro, positivo de 1 byte
{
	Domingo = 0,
	Segunda = 1,
	Terca = 2,
	Quarta = 3,
	Quinta = 4,
	Sexta = 5,
	Sabado = 6
};