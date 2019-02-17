#ifndef ALBERO_BINARIO_PUNTATORE_H
#define ALBERO_BINARIO_PUNTATORE_H

#include "NodoPuntatore.h"
#include "AlberoBinarioAstratto.h"

template<typename Dati>
class AlberoBinarioPuntatore: public AlberoBinarioAstratto <Dati,
	NodoPuntatore<Dati>*>
{
public:
	typedef typename NodoPuntatore<Dati>* Posizione;

	AlberoBinarioPuntatore()
	{
		albero = nullptr;
	}

	AlberoBinarioPuntatore(const AlberoBinarioPuntatore &alberoDaCopiare)
	{
		albero = copiaSottoAlbero(alberoDaCopiare.binRadice());
	}

	// ALGEBRA FONDAMENTALE
	void creaBinAlbero()
	{
		albero = new NodoPuntatore<Dati>();
	}

	bool binAlberoVuoto() const
	{
		return (!albero);
	}

	Posizione binRadice() const
	{
		return albero;
	}

	Posizione binPadre(Posizione nodo) const
	{
		return nodo->leggiPadre();
	}

	Posizione figlioSinistro(Posizione nodo) const
	{
		return nodo->leggiFiglioSinistro();
	}

	Posizione figlioDestro(Posizione nodo) const
	{
		return nodo->leggiFiglioDestro();
	}

	bool sinistroVuoto(Posizione nodo) const
	{
		return (!figlioSinistro(nodo));
	}

	bool destroVuoto(Posizione nodo) const
	{
		return (!figlioDestro(nodo));
	}

	void insBinRadice(Posizione radice)
	{
		albero = radice;
	}

	void insFiglioDestro(Posizione nodo, AlberoBinarioAstratto* nuovoFiglioDestro)
	{
		Posizione figlio = copiaSottoAlbero(nuovoFiglioDestro->binRadice());
		nodo->scriviFiglioDestro(figlio);
		figlio->scriviPadre(nodo);

		// Aggiorna le etichette di ogni nodo
		contaNodi(binRadice());
	}

	void insFiglioSinistro(Posizione nodo,
	                       AlberoBinarioAstratto* nuovoFiglioSinistro)
	{
		Posizione figlio = copiaSottoAlbero(nuovoFiglioSinistro->binRadice());
		nodo->scriviFiglioSinistro(figlio);
		figlio->scriviPadre(nodo);

		// Aggiorna le etichette di ogni nodo
		contaNodi(binRadice());
	}

	void cancSottoBinAlbero(Posizione nodo)
	{
		if (nodo)
		{
			if (!sinistroVuoto(nodo))
			{
				cancSottoBinAlbero(figlioSinistro(nodo));
			}

			if (!destroVuoto(nodo))
			{
				cancSottoBinAlbero(figlioDestro(nodo));
			}

			if (nodo != albero)
			{
				Posizione padre = binPadre(nodo);

				if (figlioSinistro(padre) == nodo)
				{
					padre->scriviFiglioSinistro(nullptr);
				}
				else
				{
					padre->scriviFiglioDestro(nullptr);
				}
			}
			else
			{
				albero = nullptr;
			}
		}
	}

	Dati leggiNodo(Posizione nodo) const
	{
		return nodo->leggiValore();
	}

	void scriviNodo(Dati valore, Posizione nodo)
	{
		nodo->scriviValore(valore);
	}

	// ALTRI METODI
	int leggiEtichetta(Posizione nodo) const
	{
		return nodo->leggiEtichetta();
	}

	void scriviEtichetta(int valore, Posizione nodo)
	{
		nodo->scriviEtichetta(valore);
	}

	Posizione copiaSottoAlbero(Posizione nodo)
	{
		Posizione nodoTemporaneo;

		if (!nodo)
		{
			return nullptr;
		}
		else
		{
			nodoTemporaneo = new NodoPuntatore<Dati>();
			scriviNodo(leggiNodo(nodo), nodoTemporaneo);

			if (figlioSinistro(nodo))
			{
				nodoTemporaneo->scriviFiglioSinistro(copiaSottoAlbero(figlioSinistro(nodo)));
			}

			if (figlioDestro(nodo))
			{
				nodoTemporaneo->scriviFiglioDestro(copiaSottoAlbero(figlioDestro(nodo)));
			}
		}

		return nodoTemporaneo;
	}
	
    // ATTRIBUTI
protected:
	Posizione albero;
};

#endif
