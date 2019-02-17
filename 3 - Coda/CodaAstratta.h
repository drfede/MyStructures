#ifndef CODA_ASTRATTA_H
#define CODA_ASTRATTA_H

#include <iostream>
using namespace std;

template<typename Dati>
class CodaAstratta
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaCoda() = 0;

	virtual bool codaVuota() const = 0;

	virtual Dati leggiCoda() const = 0;

	virtual void fuoriCoda() = 0;

	virtual void inCoda(Dati valore) = 0;

	// ALTRI METODI
	int leggiDimensione() const
	{
		return dimensione;
	}

	void stampa()
	{
		Dati* vettore = new Dati[leggiDimensione()];
		int dim = leggiDimensione();

		for (int i = 0; i < dim; i++)
		{
			Dati valoreTemporaneo = leggiCoda();
			vettore[i] = valoreTemporaneo;
			fuoriCoda();
		}

		for (int i = 0; i < dim; i++)
		{
			cout << vettore[i] << " ";
			inCoda(vettore[i]);
		}
	}

protected:
	int dimensione;
};

#endif
