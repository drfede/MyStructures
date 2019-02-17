#ifndef NODO_PUNTATORE_H
#define NODO_PUNTATORE_H

template<typename Dati>
class NodoPuntatore
{
public:
	NodoPuntatore()
	{
		valore = Dati();

		nodoSuccessivo = nullptr;
		nodoPrecedente = nullptr;
	}

	NodoPuntatore(Dati nuovoValore)
	{
		valore = nuovoValore;

		nodoSuccessivo = nullptr;
		nodoPrecedente = nullptr;
	}

	Dati leggiValore() const
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	NodoPuntatore* leggiNodoPrecedente() const
	{
		return nodoPrecedente;
	}

	void scriviNodoPrecedente(NodoPuntatore* nuovoNodo)
	{
		nodoPrecedente = nuovoNodo;
	}

	NodoPuntatore* leggiNodoSuccessivo() const
	{
		return nodoSuccessivo;
	}

	void scriviNodoSuccessivo(NodoPuntatore* nuovoNodo)
	{
		nodoSuccessivo = nuovoNodo;
	}

private:
	Dati valore;

	NodoPuntatore* nodoSuccessivo;
	NodoPuntatore* nodoPrecedente;
};

#endif
