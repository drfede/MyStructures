#ifndef INFO_NODO_H
#define INFO_NODO_H

template<typename Etichetta, typename Peso>
class InfoNodo
{
public:
	InfoNodo()
	{
		archi = nullptr;

		vuoto = true;

		visitato = false;
	}

	~InfoNodo()
	{
		if (!vuoto)
		{
			delete[] archi;
		}
	}

	Etichetta leggiEtichetta() const
	{
		return etichetta;
	}

	void scriviEtichetta(Etichetta nuovaEtichetta)
	{
		etichetta = nuovaEtichetta;
	}

	InfoArco<Peso>* leggiArchi() const
	{
		return archi;
	}

	InfoArco<Peso>* leggiArco(int indice) const
	{
		return &archi[indice];
	}

	void scriviArchi(InfoArco<Peso>* nuoviArchi)
	{
		archi = nuoviArchi;
	}

	bool leggiVuoto() const
	{
		return vuoto;
	}

	void scriviVuoto(bool nuovoVuoto)
	{
		vuoto = nuovoVuoto;
	}

	bool leggiVisitato()const
	{
		return visitato;
	}

	void scriviVisitato(bool nuovoVisitato)
	{
		visitato = nuovoVisitato;
	}

private:
	Etichetta etichetta;

	InfoArco<Peso>* archi;

	bool vuoto;

	bool visitato;
};

#endif