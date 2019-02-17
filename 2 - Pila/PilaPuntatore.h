#ifndef PILA_PUNTATORE_H
#define PILA_PUNTATORE_H

#include "PilaAstratta.h"
#include "NodoPuntatore.h"

template<typename Dati>
class PilaPuntatore: public PilaAstratta<Dati>
{
public:
	PilaPuntatore()
	{
		creaPila();
	}

	PilaPuntatore(PilaPuntatore &pilaOriginale)
	{
		creaPila();
		copia(pilaOriginale);
	}

	// ALGEBRA FONDAMENTALE
	void creaPila()
	{
		pila = new NodoPuntatore<Dati>();
		pila->scriviNodoSuccessivo(pila);
	}

	bool pilaVuota() const
	{
		return (pila->leggiNodoSuccessivo() == pila);
	}

	Dati leggiPila() const
	{
		return pila->leggiNodoSuccessivo()->leggiValore();
	}

	void fuoriPila()
	{
		NodoPuntatore<Dati>* nodo = pila->leggiNodoSuccessivo();
		pila->scriviNodoSuccessivo(nodo->leggiNodoSuccessivo());
		delete nodo;
	}

	void inPila(Dati nuovoValore)
	{
		NodoPuntatore<Dati>* nodo = new NodoPuntatore<Dati>();
		nodo->scriviValore(nuovoValore);
		nodo->scriviNodoSuccessivo(pila->leggiNodoSuccessivo());
		pila->scriviNodoSuccessivo(nodo);
	}

private:
	NodoPuntatore<Dati>* pila;
};

#endif
