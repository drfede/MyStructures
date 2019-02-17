#ifndef LISTA_VETTORE_H
#define LISTA_VETTORE_H

#include "ListaAstratta.h"
#include "NodoVettore.h"

template<typename Dati>
class ListaVettore : public ListaAstratta<Dati, int*>
{
public:
	typedef typename int* Posizione;

	ListaVettore()
	{
		creaLista();
	}

	// ALGEBRA FONDAMENTALE
	void creaLista()
	{
		DIMENSIONE_MASSIMA = 100;
		lista = new NodoVettore<Dati>[DIMENSIONE_MASSIMA];

		dimensione = 0;
	}

	bool listaVuota() const
	{
		return !leggiDimensione();
	}

	Dati leggiLista(Posizione nodo) const
	{
		return lista[*nodo].leggiValore();
	}

	void scriviLista(Dati valore, Posizione nodo)
	{
		lista[*nodo].scriviValore(valore);
	}

	Posizione primoLista() const
	{
		Posizione risultato = new int(0);

		return risultato;
	}

	bool fineLista(Posizione nodo) const
	{
		return (*nodo == leggiDimensione() - 1);
	}

	Posizione predLista(Posizione nodo) const
	{
		Posizione risultato = new int();
		*risultato = *nodo;

		if ((1 < *risultato) && (*risultato < leggiDimensione() + 1))
		{
			(*risultato)--;
		}

		return risultato;
	}

	Posizione succLista(Posizione nodo) const
	{
		return new int(*nodo + 1);
	}

	void insLista(Dati valore, Posizione nodo)
	{
		if (listaVuota())
		{
			scriviLista(valore, new int(0));
			dimensione++;
		}
		else if (leggiDimensione() < DIMENSIONE_MASSIMA)
		{
			for (Posizione i = new int(leggiDimensione()); *i > 0; (*i)--)
			{
				scriviLista(leggiLista(new int(*i - 1)), i);
			}

			scriviLista(valore, nodo);
			dimensione++;
		}
	}

	void cancLista(Posizione nodo)
	{

		if ((0 <= *nodo) && (*nodo < leggiDimensione()))
			if (!listaVuota())
			{
				Posizione i = new int();
				*i = *nodo;

				for (Posizione posizione = new int();
				        *i < leggiDimensione(); (*i)++)
				{
					*posizione = *i + 1;
					scriviLista(leggiLista(posizione), i);
				}

				Posizione ultimo = new int(leggiDimensione());
				scriviLista(Dati(), ultimo);

				dimensione--;
			}
	}

private:
	// ATTRIBUTI
	NodoVettore<Dati>* lista;

	int DIMENSIONE_MASSIMA;

};

#endif
