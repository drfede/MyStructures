#ifndef COPPIA_H
#define COPPIA_H

#include <iostream>
using namespace std;

template<typename Chiave, typename Dati>
class Coppia
{
public:
	Coppia()
	{
		chiave = Chiave();
		valore = Dati();
	}

	Coppia(Chiave nuovaChiave, Dati nuovoValore)
	{
		chiave = nuovaChiave;
		valore = nuovoValore;
	}

	Dati leggiValore()
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	Chiave leggiChiave()
	{
		return chiave;
	}

	void scriviChiave(Chiave nuovaChiave)
	{
		chiave = nuovaChiave;
	}

private:
	Chiave chiave;
	Dati valore;
};

template<typename Chiave, typename Dati>
ostream &operator<<(ostream &os, Coppia<Chiave, Dati> &coppia)
{
	os << coppia.leggiChiave() << ": " << coppia.leggiValore();
	return os;
}

#endif