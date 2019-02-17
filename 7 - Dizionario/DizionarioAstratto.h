#ifndef DIZIONARIO_ASTRATTO_H
#define DIZIONARIO_ASTRATTO_H

#include "Coppia.h"

#include <string>

template<typename Chiave, typename Dati>
class DizionarioAstratto
{
public:
	typedef typename Coppia<Chiave, Dati> Coppia;

	// ALGEBRA FONDAMENTALE
	virtual Dati recupera(Chiave chiave) = 0;

    virtual void inserisci(Chiave nuovaChiave, Dati nuovoValore) = 0;

	virtual void cancella(Chiave chiave) = 0;

	virtual void modifica(Chiave chiave, Dati nuovoValore) = 0;

	// ALTRI METODI
	int leggiDimensione()
	{
		return dimensione;
	}

	bool vuoto()
	{
		return !leggiDimensione();
	}

protected:
	int hash(string stringa)
	{
		int risultato = 558,
		    lunghezzaStringa = stringa.length();

		for (int i = 0; i < lunghezzaStringa; i++)
		{
			risultato = risultato * 33 + stringa[i];
		}

		return risultato;
	}

	// ATTRIBUTI
	int dimensione;
};

#endif