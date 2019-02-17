#ifndef LISTA_DI_TRABOCCO_H
#define LISTA_DI_TRABOCCO_H

#include "ListaPuntatore.h"
#include "DizionarioAstratto.h"

template<typename Chiave, typename Dati>
class ListaDiTrabocco : public DizionarioAstratto<Chiave, Dati>
{
public:
	ListaDiTrabocco(int nuovaDimensione)
	{
		DIMENSIONE_MASSIMA = nuovaDimensione;
		dimensione = 0;
		dizionario = new ListaPuntatore<Coppia>[DIMENSIONE_MASSIMA];
	}

    // ALGEBRA FONDAMENTALE
	Dati recupera( Chiave chiave)
	{
		int posizione = hash(chiave);
		NodoPuntatore<Coppia>* cursore = dizionario[posizione].primoLista();

		for (int i = 0; i < leggiDimensione(); i++)
		{
			if (chiave == dizionario[posizione].leggiLista(cursore).leggiChiave())
			{
				return dizionario[posizione].leggiLista(cursore).leggiValore();
			}

			cursore = dizionario[posizione].succLista(cursore);
		}

		return Dati();
	}

	void inserisci(Chiave nuovaChiave, Dati nuovoValore)
	{
		Coppia nuovaCoppia(nuovaChiave, nuovoValore);
		NodoPuntatore<Coppia>* posizione = dizionario[hash(nuovaChiave)].
                primoLista();
		dizionario[hash(nuovaChiave)].insLista(nuovaCoppia, posizione);

		dimensione++;
	};

	void modifica(Chiave chiave, Dati valore)
	{
		cancella(chiave);
		inserisci(chiave, valore);
	}

	void cancella(Chiave chiave)
	{
		int posizione = hash(chiave);
		NodoPuntatore<Coppia>* cursore = dizionario[posizione].primoLista();

		while (!dizionario[posizione].fineLista(cursore))
		{
			if (chiave == dizionario[posizione].leggiLista(cursore).leggiChiave())
			{
				dizionario[posizione].cancLista(cursore);
				dimensione--;
				return;
			}
			else
			{
				cursore = dizionario[posizione].succLista(cursore);
			}
		}
	}

    // ALTRI METODI
	bool appartiene(Chiave chiave)
	{
		int posizione = hash(chiave);
		NodoPuntatore<Coppia>* cursore = dizionario[posizione].primoLista();

		for (int i = 0; i < dizionario[posizione].leggiDimensione(); i++)
		{
			if (chiave == dizionario[posizione].leggiLista(cursore).leggiChiave())
			{
				return true;
			}

			cursore = dizionario[posizione].succLista(cursore);
		}

		return false;
	}

	void stampa()
	{
		for (int i = 0; i < DIMENSIONE_MASSIMA; i++)
		{
			dizionario[i].stampaLista();
		}
	};

private:
	unsigned int hash(const Chiave &chiave)
	{
		return (DizionarioAstratto::hash(chiave) % DIMENSIONE_MASSIMA);
	}

    // ATTRIBUTI
	int DIMENSIONE_MASSIMA;

	ListaPuntatore<Coppia>* dizionario;
};

#endif
