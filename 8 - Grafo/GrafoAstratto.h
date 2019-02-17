#ifndef GRAFO_ASTRATTO_H
#define GRAFO_ASTRATTO_H

#include <iostream>
using namespace std;

#include "ListaPuntatore.h"

template<typename Etichetta, typename Peso, typename Nodo, typename ListaNodi>
class GrafoAstratto
{
public:
	typedef typename ListaNodi::Posizione ListaNodiPosizione;

	// ALGEBRA FONDAMENTALE
	virtual void creaGrafo() = 0;

	virtual bool grafoVuoto() const = 0;

	virtual void insNodo(Nodo nuovoNodo) = 0;

	virtual void insArco(Nodo primoNodo, Nodo secondoNodo, Peso peso) = 0;

	virtual void cancNodo(Nodo nodo) = 0;

	virtual void cancArco(Nodo primoNodo, Nodo secondoNodo) = 0;

	virtual ListaNodi adiacenti(Nodo nodo) const = 0;

	virtual bool esisteNodo(Nodo nodo) = 0;

	virtual bool esisteArco(Nodo primoNodo, Nodo secondoNodo) = 0;

	virtual Etichetta leggiEtichetta(Nodo nodo) const = 0;

	virtual void scriviEtichetta(Nodo nodo, Etichetta nuovaEtichetta) = 0;

	virtual bool leggiVisitato(Nodo nodo) const = 0;

	virtual void scriviVisitato(Nodo nodo, bool nuovoVisitato) = 0;

	// ALTRI METODI
	void visitaProfondita(Nodo nodo)
	{
		dfs(nodo);

		resetFlagVisitato(nodo);
	}

	int leggiNumeroNodi()const
	{
		return nodi;
	}

	int leggiNumeroArchi() const
	{
		return archi;
	}

	int leggiDimensione() const
	{
		return dimensione;
	}

private:
	void dfs(Nodo nodo)
	{
		// esamina il nodo
		if (!leggiVisitato(nodo))
		{
			cout << leggiEtichetta(nodo) << " ";

			// marca il nodo come "visitato"
			scriviVisitato(nodo, true);

			// recupera la lista dei nodi adiacenti
			ListaNodi lista = adiacenti(nodo);

			ListaNodiPosizione nodoTemporaneo = lista.primoLista();

			// per ogni nodo adiacente
			for (int i = 0; i < lista.leggiDimensione(); i++)
			{
				// se il nodo non è stato visitato
				if (!leggiVisitato(*lista.leggiLista(nodoTemporaneo)))
				{
					// si richiama ricorsivamente
					dfs(*lista.leggiLista(nodoTemporaneo));
				}

				nodoTemporaneo = lista.succLista(nodoTemporaneo);
			}
		}
	}

	void resetFlagVisitato(Nodo nodo)
	{
		// esamina il nodo
		if (leggiVisitato(nodo))
		{
			// marca il nodo come "non visitato"
			scriviVisitato(nodo, false);

			// recupera la lista dei nodi adiacenti
			ListaNodi lista = adiacenti(nodo);

			ListaNodiPosizione nodoTemporaneo = lista.primoLista();

			// per ogni nodo adiacente
			for (int i = 0; i < lista.leggiDimensione(); i++)
			{
				// se il nodo è stato visitato
				if (leggiVisitato(*lista.leggiLista(nodoTemporaneo)))
				{
					// si richiama ricorsivamente
					resetFlagVisitato(*lista.leggiLista(nodoTemporaneo));
				}

				nodoTemporaneo = lista.succLista(nodoTemporaneo);
			}
		}
	}

protected:
	int dimensione;
	int nodi;
	int archi;
};


#endif
