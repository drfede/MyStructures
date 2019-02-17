#ifndef ALBERO_BINARIO_CURSORE_H
#define ALBERO_BINARIO_CURSORE_H

#include <iostream>
using namespace std;

#include "NodoCursore.h"

template <typename Dati>
class AlberoBinarioCursore
{
public:
	typedef int* Posizione;

	AlberoBinarioCursore()
	{
		DIMENSIONE_MASSIMA = 100;
		albero = new NodoCursore<Dati>[DIMENSIONE_MASSIMA];
		creaBinAlbero();
	}

	AlberoBinarioCursore(int nuovaDimensione)
	{
		DIMENSIONE_MASSIMA = nuovaDimensione;
		albero = new NodoCursore<Dati>[DIMENSIONE_MASSIMA];
		creaBinAlbero();
	}

	// ALGEBRA FONDAMENTALE
	void creaBinAlbero()
	{
		inizio = new int(-1);

		for (int i = 0; i < DIMENSIONE_MASSIMA; i++)
		{
			albero[i].scriviFiglioSinistro(new int((i + 1) % DIMENSIONE_MASSIMA));

		}

		libera = new int(0);

		nodi = 0;
	}

	bool binAlberoVuoto() const
	{
		return (!nodi);
	}

	Posizione binRadice() const
	{
		return inizio;
	}

	Posizione binPadre(Posizione nodo) const
	{
		return (albero[*nodo].leggiPadre());
	}

	Posizione figlioSinistro(Posizione nodo) const
	{
		return albero[*nodo].leggiFiglioSinistro();
	}

	Posizione figlioDestro(Posizione nodo) const
	{
		return (albero[*nodo].leggiFiglioDestro());
	}

	bool sinistroVuoto(Posizione nodo) const
	{
		return (*(albero[*nodo].leggiFiglioSinistro()) == -1);
	}

	bool destroVuoto(Posizione nodo) const
	{
		return (*(albero[*nodo].leggiFiglioDestro()) == -1);
	}

	void insBinRadice(Posizione nodo)
	{
		if (*inizio == -1)
		{
			inizio = new int(*libera);
			libera = albero[*libera].leggiFiglioSinistro();
			albero[*inizio].scriviFiglioSinistro(new int(-1));
			albero[*inizio].scriviFiglioDestro(new int(-1));
			nodi++;
		}
	}

	void insFiglioDestro(Posizione nuovoFiglioDestro)
	{
		Posizione nodo = libera;

		libera = albero[*libera].leggiFiglioSinistro();

		albero[*nuovoFiglioDestro].scriviFiglioDestro(nodo);
		albero[*nodo].scriviPadre(nuovoFiglioDestro);
		albero[*nodo].scriviFiglioSinistro(new int(-1));
		albero[*nodo].scriviFiglioDestro(new int(-1));

		nodi++;
	}

	void insFiglioSinistro(Posizione nuovoFiglioSinistro)
	{
		Posizione nodo = libera;

		libera = albero[*libera].leggiFiglioSinistro();

		albero[*nuovoFiglioSinistro].scriviFiglioSinistro(nodo);
		albero[*nodo].scriviPadre(nuovoFiglioSinistro);
		albero[*nodo].scriviFiglioSinistro(new int(-1));
		albero[*nodo].scriviFiglioDestro(new int(-1));

		nodi++;
	}

	Dati leggiNodo(Posizione nodo) const
	{
		return albero[*nodo].leggiValore();
	}

	void scriviNodo(Dati valore, Posizione nodo)
	{
		albero[*nodo].scriviValore(valore);
	}

	// ALTRI METODI
	void cancSottoBinAlbero(Posizione nodo)
	{
		if (!albero[*nodo].leggiVuoto())
		{
			if (!sinistroVuoto(nodo))
			{
				cancSottoBinAlbero(figlioSinistro(nodo));
			}

			if (!destroVuoto(nodo))
			{
				cancSottoBinAlbero(figlioDestro(nodo));
			}

			if (nodo != inizio)
			{
				Posizione nodoTemporaneo = binPadre(nodo);

				if (figlioSinistro(nodoTemporaneo) == nodo)
				{
					albero[*nodoTemporaneo].leggiFiglioSinistro().scriviVuoto(true);
				}
				else
				{
					albero[*nodoTemporaneo].leggiFiglioDestro().scriviVuoto(true);
				}
			}
			else
			{
				inizio = nullptr;
			}

			nodi--;
			albero[*nodo].scriviFiglioSinistro(libera);
			libera = nodo;
		}
	}

	void stampa() const
	{
		if (!binAlberoVuoto())
		{
			visitaPreOrdine(binRadice());
		}
		else
		{
			cout << "[]";
		}

		cout << endl;
	}

	void visitaPreOrdine(Posizione nodo) const
	{
		if (!binAlberoVuoto())
		{
			cout << leggiNodo(nodo) << " ";

			if (!sinistroVuoto(nodo))
			{
				visitaPreOrdine(figlioSinistro(nodo));
			}

			if (!destroVuoto(nodo))
			{
				visitaPreOrdine(figlioDestro(nodo));
			}
		}
	}
private:
	// ATTRIBUTI
	NodoCursore<Dati>* albero;

	int DIMENSIONE_MASSIMA;

	int nodi;

	Posizione inizio;

	Posizione libera;
};

#endif
