#ifndef LISTA_ORDINATA_H
#define LISTA_ORDINATA_H

#include "ListaPuntatore.h"

template<typename Dati>
class ListaOrdinata : public ListaPuntatore<Dati>
{
public:
	void insLista(Dati valore);

	void fondi(const ListaOrdinata<Dati> &secondaLista);
};

template<typename Dati>
void ListaOrdinata<Dati>::insLista(Dati valore)
{
	int i = 0;
	Posizione cursore = primoLista();

	while (i < leggiDimensione() && (valore > leggiLista(cursore)))
	{
		cursore = succLista(cursore);
		i++;
	}

	ListaPuntatore::insLista(valore, cursore);
}

template<typename Dati>
void ListaOrdinata<Dati>::fondi(const ListaOrdinata<Dati> &secondaLista)
{
	ListaOrdinata<Dati>* copia = new ListaOrdinata(secondaLista);

	while (!copia->listaVuota())
	{
		insLista(leggiLista(copia->primoLista()));
		cancLista(copia->primoLista());
	}
}

#endif