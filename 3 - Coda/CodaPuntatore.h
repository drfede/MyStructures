#ifndef CODA_PUNTATORE_H
#define CODA_PUNTATORE_H

#include "CodaAstratta.h"
#include "NodoPuntatore.h"

template<typename Dati>
class CodaPuntatore: public CodaAstratta<Dati>
{
public:
	CodaPuntatore()
	{
		creaCoda();
	}

	CodaPuntatore(CodaPuntatore &coda)
	{

		creaCoda();

		for (int i = 0; i < coda.leggiDimensione(); i++)
		{
			inCoda(coda.leggiCoda());
			coda.inCoda(coda.leggiCoda());
			coda.fuoriCoda();
		}
	}

	// ALGEBRA FONDAMENTALE
	void creaCoda()
	{
		coda = new NodoPuntatore<Dati>();
		coda->scriviNodoSuccessivo(coda);
		dimensione = 0;
	}

	bool codaVuota() const
	{
		return (coda->leggiNodoSuccessivo() == coda);
	}

	Dati leggiCoda() const
	{
		NodoPuntatore<Dati>* nodo = coda;

		while (nodo->leggiNodoSuccessivo() != coda)
		{
			nodo = nodo->leggiNodoSuccessivo();
		}

		return nodo->leggiValore();
	}

	void fuoriCoda()
	{
		NodoPuntatore<Dati>* nodo = coda;

		while (nodo->leggiNodoSuccessivo() != coda)
		{
			nodo = nodo->leggiNodoSuccessivo();
		}

		nodo->leggiNodoPrecedente()->scriviNodoSuccessivo(coda);
		coda->scriviNodoPrecedente(nodo->leggiNodoPrecedente());
		delete nodo;
		dimensione--;
	}

	void inCoda(Dati valore)
	{
		NodoPuntatore<Dati>* nodo = new NodoPuntatore<Dati>();
		nodo->scriviValore(valore);
		nodo->scriviNodoSuccessivo(coda->leggiNodoSuccessivo());
		nodo->scriviNodoPrecedente(coda);
		coda->leggiNodoSuccessivo()->scriviNodoPrecedente(nodo);
		coda->scriviNodoSuccessivo(nodo);
		dimensione++;
	}

private:
	NodoPuntatore<Dati>* coda;
};

#endif
