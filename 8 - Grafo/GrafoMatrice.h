#ifndef GRAFO_MATRICE_H
#define GRAFO_MATRICE_H

#include "GrafoAstratto.h"
#include "InfoArco.h"
#include "InfoNodo.h"
#include "NodoGrafo.h"
#include "ListaVettore.h"

template<typename Etichetta, typename Peso>
class GrafoMatrice : public
	GrafoAstratto<Etichetta, Peso, NodoGrafo &, ListaVettore<NodoGrafo*>>
{
public:
	typedef NodoGrafo &Nodo;
	typedef ListaVettore<NodoGrafo*> ListaNodi;
	typedef GrafoAstratto<Etichetta, Peso, Nodo, ListaVettore<NodoGrafo*>>
	        GrafoAstratto;

	GrafoMatrice()
	{
		creaGrafo();
	}

	~GrafoMatrice()
	{
		delete[] grafo;
	}

	// ALGEBRA FONDAMENTALE
	void creaGrafo()
	{
		dimensione = 100;
		nodi = 0;
		archi = 0;
		grafo = new InfoNodo<Etichetta, Peso>[dimensione];

		for (int i = 0; i < dimensione; i++)
		{
			grafo[i].scriviArchi(new InfoArco<Peso>[dimensione]);
		}
	}

	bool grafoVuoto() const
	{
		return !leggiNumeroNodi();
	}

	void insNodo(Nodo nuovoNodo)
	{
		int n = 0;

		if (leggiNumeroNodi() < dimensione)
		{
			while (!grafo[n].leggiVuoto())
			{
				n++;
			}

			nodi++;
			grafo[n].scriviVuoto(false);
		}

		nuovoNodo.scriviIDnodo(n);
	}

	void insArco(Nodo primoNodo, Nodo secondoNodo, Peso peso)
	{
		grafo[primoNodo.leggiIDnodo()].leggiArco(
		    secondoNodo.leggiIDnodo())->scriviPeso(peso);

		grafo[primoNodo.leggiIDnodo()].leggiArco(
		    secondoNodo.leggiIDnodo())->scriviVuoto(false);
		archi++;
	}

	void cancNodo(Nodo nodo)
	{
		bool canc = true;
		int i;

		for (i = 0; i < dimensione && canc; i++)
			if (!grafo[nodo.leggiIDnodo()].leggiArco(i)->leggiVuoto())
			{
				canc = false;
			}

		for (i = 0; i < dimensione && canc; i++)
			if (!grafo[i].leggiVuoto() &&
			        !grafo[i].leggiArco(nodo.leggiIDnodo())->leggiVuoto())
			{
				canc = false;
			}

		if (canc)
		{
			delete grafo[nodo.leggiIDnodo()].leggiArchi();
			grafo[nodo.leggiIDnodo()].scriviVuoto(true);
			nodi--;
		}
	}

	void cancArco(Nodo primoNodo, Nodo secondoNodo)
	{
		grafo[primoNodo.leggiIDnodo()].leggiArco(
		    secondoNodo.leggiIDnodo())->scriviVuoto(true);
		archi--;
	}

	bool esisteNodo(Nodo nodo)
	{
		return ((!grafo[nodo.leggiIDnodo()].leggiVuoto()) &&
		        (nodo.leggiIDnodo() == -1));
	}

	bool esisteArco(Nodo primoNodo, Nodo secondoNodo)
	{
		return !grafo[primoNodo.leggiIDnodo()].leggiArco(
		           secondoNodo.leggiIDnodo())->leggiVuoto();
	}

	ListaNodi adiacenti(Nodo n) const
	{
		ListaNodi lista;

		for (int i = 0; i < leggiNumeroNodi(); i++)
		{
			if (!grafo[n.leggiIDnodo()].leggiArco(i)->leggiVuoto())
			{
				lista.insLista(new NodoGrafo(i), lista.primoLista());
			}
		}

		return lista;
	}

	Etichetta leggiEtichetta(Nodo nodo) const
	{
		return grafo[nodo.leggiIDnodo()].leggiEtichetta();
	}

	void scriviEtichetta(Nodo nodo, Etichetta nuovaEtichetta)
	{
		grafo[nodo.leggiIDnodo()].scriviEtichetta(nuovaEtichetta);
	}

	Peso leggiPeso(Nodo nodo1, Nodo nodo2) const
	{
		return grafo[nodo1.leggiIDnodo()].leggiArco(nodo2.leggiIDnodo())->
                leggiPeso();
	}

	void scriviPeso(Nodo nodo1, Nodo nodo2, Peso peso)
	{
		grafo[nodo1.leggiIDnodo()].leggiArco(nodo2.leggiIDnodo())->
                scriviPeso(peso);
	}

	bool leggiVisitato(Nodo nodo) const
	{
		return grafo[nodo.leggiIDnodo()].leggiVisitato();
	}

	void scriviVisitato(Nodo nodo, bool nuovoVisitato)
	{
		grafo[nodo.leggiIDnodo()].scriviVisitato(nuovoVisitato);
	}

private:
	InfoNodo<Etichetta, Peso>* grafo;
};

#endif
