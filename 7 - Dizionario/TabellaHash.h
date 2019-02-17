#ifndef TABELLA_HASH_H
#define TABELLA_HASH_H

#include "DizionarioAstratto.h"

template<typename Chiave, typename Dati>
class TabellaHash : public DizionarioAstratto<Chiave, Dati>
{
public:
	TabellaHash()
	{
		creaDizionario();
	}

    // ALGEBRA FONDAMENTALE
	void inserisci(Chiave nuovaChiave, Dati nuovoValore)
	{
		int i = cerca(nuovaChiave);
		
        if (!dizionario[i])
		{
			dizionario[i] = new Coppia<Chiave, Dati>(nuovaChiave, nuovoValore);
			dimensione++;
		}
		else if (dizionario[i]->leggiChiave() == nuovaChiave)
				modifica(nuovaChiave, nuovoValore);
	}

	void cancella(Chiave chiave)
	{
		int i = cerca(chiave);

		if (recupera(i))
			delete dizionario[i];
	}
	
    void modifica(Chiave chiave, Dati nuovoValore)
	{
		if (recupera(chiave))
			recupera(chiave)->scriviValore(nuovoValore);
	}

	Coppia* recupera(Chiave chiave) const
	{
		int i = cerca(chiave);
		if (dizionario[i] == nullptr || dizionario[i]->leggiChiave() != chiave)
			return nullptr;
		return dizionario[i];
	}

    // ALTRI METODI
	void creaDizionario()
	{
		DIMENSIONE_MASSIMA = 100;

		dimensione = 0;

		dizionario = new Coppia*[DIMENSIONE_MASSIMA];

		for (int i = 0; i < DIMENSIONE_MASSIMA; i++)
			dizionario[i] = nullptr;
	}

	int cerca(Chiave chiave) const
	{
		int i = (int)hash(chiave) % DIMENSIONE_MASSIMA;
		
        int j = i;
		
        do
		{
			if (dizionario[j] == nullptr || dizionario[j]->leggiChiave() 
                    == chiave)
				return j;
			j = (j + 1) % DIMENSIONE_MASSIMA;
		} while (j != i);

		return j;
	}

private:    
	int DIMENSIONE_MASSIMA;

	Coppia** dizionario;
};

#endif