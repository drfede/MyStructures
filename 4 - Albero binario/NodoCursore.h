#ifndef NODO_CURSORE_H
#define NODO_CURSORE_H

template<typename Dati>
class NodoCursore
{
public:
	NodoCursore()
	{
		scriviValore(Dati());
		scriviEtichetta(0);
	}

	NodoCursore(Dati nuovoValore)
	{
		scriviValore(nuovoValore);
		scriviVuoto(true);
		scriviEtichetta(0);
	};

	Dati leggiValore() const
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	int* leggiPadre() const
	{
		return padre;
	}

	void scriviPadre(int* nuovoPadre)
	{
		padre = nuovoPadre;
	}

	int* leggiFiglioSinistro() const
	{
		return figlioSinistro;
	}

	void scriviFiglioSinistro(int* nuovoFiglioSinistro)
	{
		figlioSinistro = nuovoFiglioSinistro;
	}

	int* leggiFiglioDestro() const
	{
		return figlioDestro;
	}

	void scriviFiglioDestro(int* nuovoFiglioDestro)
	{
		figlioDestro = nuovoFiglioDestro;
	}

	int leggiEtichetta() const
	{
		return etichetta;
	}

	void scriviEtichetta(int nuovaEtichetta)
	{
		etichetta = nuovaEtichetta;
	}

private:
	Dati valore;

	int etichetta;

	int* figlioSinistro;
	int* figlioDestro;
	int* padre;
};


#endif