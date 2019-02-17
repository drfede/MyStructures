#ifndef NODO_PUNTATORE_H
#define NODO_PUNTATORE_H

template<typename Dati>
class NodoPuntatore
{
public:
	NodoPuntatore()
	{
		scriviEtichetta(0);

		scriviFiglioSinistro(nullptr);
		scriviFiglioDestro(nullptr);
		scriviPadre(nullptr);
	}

	NodoPuntatore(Dati nuovoValore)
	{
		valore = nuovoValore;

		scriviEtichetta(0);

		scriviFiglioSinistro(nullptr);
		scriviFiglioDestro(nullptr);
		scriviPadre(nullptr);
	}

	Dati leggiValore() const
	{
		return valore;
	}

	void scriviValore(Dati nuovoValore)
	{
		valore = nuovoValore;
	}

	NodoPuntatore* leggiPadre() const
	{
		return padre;
	}

	void scriviPadre(NodoPuntatore* nuovoPadre)
	{
		padre = nuovoPadre;
	}

	NodoPuntatore* leggiFiglioSinistro() const
	{
		return figlioSinistro;
	}

	void scriviFiglioSinistro(NodoPuntatore* nuovoFiglioSinistro)
	{
		figlioSinistro = nuovoFiglioSinistro;
	}

	NodoPuntatore* leggiFiglioDestro() const
	{
		return figlioDestro;
	}

	void scriviFiglioDestro(NodoPuntatore* nuovoFiglioDestro)
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

	NodoPuntatore* figlioSinistro;
	NodoPuntatore* figlioDestro;
	NodoPuntatore* padre;
};

#endif