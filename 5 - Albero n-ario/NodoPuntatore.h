#ifndef NODO_PUNTATORE_H
#define NODO_PUNTATORE_H

template<typename Dati>
class NodoPuntatore
{
public:
	NodoPuntatore()
	{
		scriviValore(Dati());
		scriviPrimoFiglio(nullptr);
		scriviFratelloSuccessivo(nullptr);
		scriviPadre(nullptr);
	}

	NodoPuntatore(Dati valore)
	{
		scriviValore(valore);
		scriviPrimoFiglio(nullptr);
		scriviFratelloSuccessivo(nullptr);
		scriviPadre(nullptr);
	}

	NodoPuntatore* leggiPrimoFiglio() const
	{
		return primoFiglio;
	}

	void scriviPrimoFiglio(NodoPuntatore* nodo)
	{
		primoFiglio = nodo;
	}

	NodoPuntatore* leggiFratelloSuccessivo() const
	{
		return fratelloSuccessivo;
	}

	void scriviFratelloSuccessivo(NodoPuntatore* nodo)
	{
		fratelloSuccessivo = nodo;
	}

	NodoPuntatore* leggiPadre() const
	{
		return padre;
	}

	void scriviPadre(NodoPuntatore* nodo)
	{
		padre = nodo;
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

	NodoPuntatore* primoFiglio;
	NodoPuntatore* fratelloSuccessivo;
	NodoPuntatore* padre;
};

#endif
