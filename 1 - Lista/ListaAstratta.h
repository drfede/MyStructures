#ifndef LISTA_ASTRATTA_H
#define LISTA_ASTRATTA_H

#include <iostream>
using namespace std;

template<typename Dati, typename Posizione>
class ListaAstratta
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaLista() = 0;

	virtual bool listaVuota() const = 0;

	virtual Dati leggiLista(Posizione nodo) const = 0;

	virtual void scriviLista(Dati nuovoValore, Posizione nodo) = 0;

	virtual Posizione primoLista() const = 0;

	virtual bool fineLista(Posizione nodo) const = 0;

	virtual Posizione succLista(Posizione nodo) const = 0;

	virtual Posizione predLista(Posizione nodo) const = 0;

	virtual void insLista(Dati nuovoValore, Posizione nodo) = 0;

	virtual void cancLista(Posizione nodo) = 0;

	// ALTRI METODI
	Posizione ultimoLista()
	{
		Posizione nodo = primoLista();

		while (!fineLista(nodo))
		{
			nodo = succLista(nodo);
		}

		return nodo;
	}

	int leggiDimensione() const
	{
		return dimensione;
	}

	bool cerca(Dati valore) const
	{
		Posizione nodo = primoLista();

		for (int i = 0; i < leggiDimensione(); i++)
		{
			if (leggiLista(nodo) == valore)
			{
				return true;
			}

			nodo = succLista(nodo);
		}

		return false;
	}

	void stampa() const
	{
		cout << "[";
		Posizione nodo = primoLista();

		if (!listaVuota())
		{
			while (!fineLista(nodo))
			{
				cout << leggiLista(nodo);

				cout << ", ";

				nodo = succLista(nodo);
			}

			cout << leggiLista(nodo);
		}

		cout << "]\n\n";
	}

	void rimuoviDuplicati()
	{
		Posizione nodo = primoLista(),
		          nodoTemporaneo;

		while (!fineLista(nodo))
		{
			nodoTemporaneo = succLista(nodo);

			while (!fineLista(nodoTemporaneo))
			{
				if (leggiLista(nodo) == leggiLista(nodoTemporaneo))
				{
					cancLista(nodoTemporaneo);

					nodoTemporaneo = succLista(nodo);
				}
				else
				{
					nodoTemporaneo = succLista(nodoTemporaneo);
				}
			}

			if (leggiLista(nodo) == leggiLista(nodoTemporaneo))
			{
				cancLista(nodoTemporaneo);

				nodoTemporaneo = succLista(nodo);
			}
			else
			{
				nodoTemporaneo = succLista(nodoTemporaneo);
			}

			nodo = succLista(nodo);
		}
	}

protected:
	// ATTRIBUTI
	int dimensione;
};

#endif