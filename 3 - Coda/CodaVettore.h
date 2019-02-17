#ifndef CODAVETTORE_H
#define CODAVETTORE_H

#include "CodaAstratta.h"
#include "NodoVettore.h"

template<typename Dati>
class CodaVettore : public CodaAstratta<Dati>
{
public:
	CodaVettore()
	{
		creaCoda();
	}

	// ALGEBRA FONDAMENTALE
	void creaCoda()
	{
		DIMENSIONE_MASSIMA = 100;
		coda = new NodoVettore<Dati>[DIMENSIONE_MASSIMA];

		dimensione = 0;
	}

	bool codaVuota() const
	{
		return !leggiDimensione();
	}

	Dati leggiCoda() const
	{
				return coda[dimensione - 1].leggiValore();
	}

	void fuoriCoda()
	{
				dimensione--;
				coda[dimensione].scriviValore(Dati());
		}

	void inCoda(Dati valore)
	{
			if (dimensione < DIMENSIONE_MASSIMA - 1)
			{
				for (int i = dimensione; i > 0; i--)
				{
					coda[i] = coda[i - 1];
				}

				coda[0].scriviValore(valore);
				dimensione++;
			}
		}

private:
	// ATTRIBUTI
	int DIMENSIONE_MASSIMA;

	NodoVettore<Dati>* coda;
};


#endif
