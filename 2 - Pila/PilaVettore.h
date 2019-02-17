#ifndef PILA_VETTORE_H
#define PILA_VETTORE_H

#include "PilaAstratta.h"
#include "NodoVettore.h"

template<typename Dati>
class PilaVettore : public PilaAstratta <Dati>
{
public:
	PilaVettore()
	{
		creaPila();
	}

	PilaVettore(PilaVettore& pilaOriginale)
	{
		creaPila();
		copia(pilaOriginale);
    }


	// ALGEBRA FONDAMENTALE
	void creaPila()
	{
		DIMENSIONE_MASSIMA = 100;
		dimensione = 0;
		pila = new NodoVettore<Dati>[DIMENSIONE_MASSIMA];
	}

	bool pilaVuota() const
	{
		return (!dimensione);
	}

	Dati leggiPila() const
	{
		return pila[dimensione - 1].leggiValore();
	}

	void fuoriPila()
	{
		pila[dimensione - 1].scriviValore(Dati());
		dimensione--;
	}

	void inPila(Dati nuovoValore)
	{
		pila[dimensione].scriviValore(nuovoValore);
		dimensione++;
	}

private:
	// ATTRIBUTI
	int DIMENSIONE_MASSIMA;

	NodoVettore<Dati>* pila;
};

#endif