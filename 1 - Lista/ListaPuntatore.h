#ifndef LISTA_PUNTATORE_H
#define LISTA_PUNTATORE_H

#include "ListaAstratta.h"
#include "NodoPuntatore.h"

template<typename Dati>
class ListaPuntatore : public ListaAstratta<Dati, NodoPuntatore<Dati>*>
{
public:
	typedef typename NodoPuntatore<Dati>* Posizione;

	ListaPuntatore()
	{
		creaLista();
	}

	ListaPuntatore(const ListaPuntatore &listaOriginale)
	{
		creaLista();
		Posizione cursore = listaOriginale.primoLista(),
		          cursoreTemporaneo = primoLista();

		for (int i = 0; i < listaOriginale.leggiDimensione(); i++)
		{
			insLista(leggiLista(cursore), cursoreTemporaneo);
			cursore = listaOriginale.succLista(cursore);
			//  cursoreTemporaneo = succLista(cursoreTemporaneo);
		}
	}

	// ALGEBRA FONDAMENTALE
	void creaLista()
	{
		lista = new NodoPuntatore<Dati>();

		lista->scriviNodoSuccessivo(lista);
		lista->scriviNodoPrecedente(lista);

		dimensione = 0;
	}

	bool listaVuota() const
	{
		return (!leggiDimensione());
	}

	Dati leggiLista(Posizione nodo) const
	{
		return nodo->leggiValore();
	}

	void scriviLista(Dati nuovoValore, Posizione nodo)
	{
		nodo->scriviValore(nuovoValore);
	}

	Posizione primoLista() const
	{
		return succLista(lista);
	}

	bool fineLista(Posizione nodo) const
	{
		return (succLista(nodo) == lista);
	}

	Posizione succLista(Posizione nodo) const
	{
		return nodo->leggiNodoSuccessivo();
	}

	Posizione predLista(Posizione nodo) const
	{
		return nodo->leggiNodoPrecedente();
	}

	void insLista(Dati nuovoValore, Posizione nodo)
	{
		Posizione nodoTemporaneo = new NodoPuntatore<Dati>(nuovoValore);

		nodoTemporaneo->scriviNodoPrecedente(predLista(nodo));
		nodoTemporaneo->scriviNodoSuccessivo(nodo);

		(predLista(nodo))->scriviNodoSuccessivo(nodoTemporaneo);

		nodo->scriviNodoPrecedente(nodoTemporaneo);

		dimensione++;
	}

	void cancLista(Posizione nodo)
	{
		Posizione nodoTemporaneo = nodo;

		succLista(nodo)->scriviNodoPrecedente(predLista(nodo));
		predLista(nodo)->scriviNodoSuccessivo(succLista(nodo));

		delete nodoTemporaneo;

		dimensione--;
	}

private:
	// ATTRIBUTI
	Posizione lista;
};

#endif
