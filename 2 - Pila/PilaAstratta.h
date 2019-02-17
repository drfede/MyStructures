#ifndef PILA_ASTRATTA_H
#define PILA_ASTRATTA_H

#include <iostream>
using namespace std;

template<typename Dati>
class PilaAstratta
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaPila() = 0;

	virtual bool pilaVuota() const = 0;

	virtual Dati leggiPila() const = 0;

	virtual void fuoriPila() = 0;

	virtual void inPila(Dati nuovoValore) = 0;

	// ALTRI METODI
	int leggiDimensione()
	{
		return dimensione;
	}

	void stampa()
	{
		if (!pilaVuota())
		{
			Dati valoreTemporaneo = leggiPila();
			cout << valoreTemporaneo << " ";
			fuoriPila();
			stampa();
			inPila(valoreTemporaneo);
		}
	}

	void copia(PilaAstratta &pilaOriginale)
	{
		if (!pilaOriginale.pilaVuota())
		{
			Dati valoreTemporaneo = pilaOriginale.leggiPila();
			pilaOriginale.fuoriPila();
			copia(pilaOriginale);
			pilaOriginale.inPila(valoreTemporaneo);
			inPila(valoreTemporaneo);
		}
	}

protected:
	// ATTRIBUTI
	int dimensione;
};

#endif
