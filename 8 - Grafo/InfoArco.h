#ifndef INFO_ARCO_H
#define INFO_ARCO_H

template<typename Peso>
class InfoArco
{
public:
	InfoArco()
	{
		peso = Peso();
		vuoto = true;
	}

	Peso leggiPeso() const
	{
		return peso;
	}

	void scriviPeso(Peso nuovoPeso)
	{
		peso = nuovoPeso;
	}

	bool leggiVuoto() const
	{
		return vuoto;
	}

	void scriviVuoto(bool nuovoVuoto)
	{
		vuoto = nuovoVuoto;
	}

private:
	Peso peso;
	bool vuoto;
};

#endif