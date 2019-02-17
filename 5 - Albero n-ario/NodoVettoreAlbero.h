#ifndef NODO_VETTORE_ALBERO_H
#define NODO_VETTORE_ALBERO_H

#include "ListaVettore.h"

template<typename Dati>
class NodoVettoreAlbero
{public:
	NodoVettoreAlbero()
	{
		usato = false;
		listaFigli = ListaVettore<int>();
		valore = Dati();
	}

	Dati leggiValore() const
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	bool leggiUsato() const
	{
		return usato;
	}
    
    void scriviUsato(bool nuovoUsato)
	{
		usato = nuovoUsato;
	}

	ListaVettore<int>* leggiListaFigli()
	{
		return &listaFigli;
	}

private:
	bool usato;

	Dati valore;

	ListaVettore<int> listaFigli;
};

#endif