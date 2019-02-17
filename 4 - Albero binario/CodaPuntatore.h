#ifndef CODAPUNTATORE_H
#define CODAPUNTATORE_H

#include "NodoPuntatore.h"
#include "CodaAstratta.h"

template<typename Dati>
class CodaPuntatore: public CodaAstratta<Dati>
{
public:
	CodaPuntatore()
	{
		coda = nullptr;
	}

	// ALGEBRA FONDAMENTALE
	void creaCoda()
	{
		coda = new Nodo<Dati>();
		coda->scriviNodoSuccessivo(coda);
		dimensione = 0;
	}

	bool codaVuota() const
	{
		return (coda->leggiNodoSuccessivo() == coda);
	}

	Dati leggiCoda() const
	{
		Nodo<Dati>* nodo = coda;

		while (nodo->leggiNodoSuccessivo() != coda)
		{
			nodo = nodo->leggiNodoSuccessivo();
		}

		return nodo->leggiCella();
	}

	void fuoriCoda()
	{
		Nodo<Dati>* nodo = coda;

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
		Nodo<Dati>* nodo = new Nodo<Dati>();
		nodo->scriviCella(valore);
		nodo->scriviNodoSuccessivo(coda->leggiNodoSuccessivo());
		nodo->scriviNodoPrecedente(coda);
		coda->leggiNodoSuccessivo()->scriviNodoPrecedente(nodo);
		coda->scriviNodoSuccessivo(nodo);
		dimensione++;
	}

private:
	Nodo<Dati>* coda;
};

#endif
