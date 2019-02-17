#ifndef NODO_VETTORE_H
#define NODO_VETTORE_H

template<typename Dati>
class NodoVettore
{
public:
	NodoVettore()
	{
		valore = Dati();
	}

	NodoVettore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	Dati leggiValore() const
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

private:
	Dati valore;
};

#endif
