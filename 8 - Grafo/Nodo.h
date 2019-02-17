#ifndef NODO_H
#define NODO_H

#include "Cella.h"

template<typename Dati>
class Nodo: public Cella<Dati>
{
public:
	Nodo()
	{
		scriviNodoSuccessivo(nullptr);
		scriviNodoPrecedente(nullptr);
	}

	Nodo(Dati valore) : Cella(valore)
	{
		scriviNodoSuccessivo(nullptr);
		scriviNodoPrecedente(nullptr);
	}

	void scriviNodoSuccessivo(Nodo* nodo)
	{
		nodoSuccessivo = nodo;
	}

	Nodo* leggiNodoSuccessivo() const
	{
		return nodoSuccessivo;
	}

	void scriviNodoPrecedente(Nodo* nodo)
	{
		nodoPrecedente = nodo;
	}

	Nodo* leggiNodoPrecedente() const
	{
		return nodoPrecedente;
	}

private:
	Dati valore;

	Nodo* nodoSuccessivo;
	Nodo* nodoPrecedente;
};







#endif