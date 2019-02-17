#ifndef ALBERO_BINARIO_ASTRATTO_H
#define ALBERO_BINARIO_ASTRATTO_H

#include <iostream>
using namespace std;

template<typename Dati, typename Posizione>
class AlberoBinarioAstratto
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaBinAlbero() = 0;

	virtual bool binAlberoVuoto() const = 0;

	virtual Posizione binRadice() const = 0;

	virtual Posizione binPadre(Posizione nodo) const = 0;

	virtual Posizione figlioSinistro(Posizione nodo) const = 0;

	virtual Posizione figlioDestro(Posizione nodo) const = 0;

	virtual bool sinistroVuoto(Posizione nodo) const = 0;

	virtual bool destroVuoto(Posizione nodo) const = 0;

	virtual void insBinRadice(Posizione nodo) = 0;

	virtual void insFiglioSinistro(Posizione nodo, AlberoBinarioAstratto* 
            nuovoFiglioSinistro) = 0;

	virtual void insFiglioDestro(Posizione nodo,  AlberoBinarioAstratto* 
            nuovoFiglioDestro) = 0;

	virtual void cancSottoBinAlbero(Posizione nodo) = 0;

	virtual Dati leggiNodo(Posizione nodo) const = 0;

	virtual void scriviNodo(Dati valore, Posizione nodo) = 0;

	// ALTRI METODI
	virtual int leggiEtichetta(Posizione nodo) const = 0;

	virtual void scriviEtichetta(int valore, Posizione nodo) = 0;

	bool foglia(Posizione nodo) const
	{
		return (sinistroVuoto(nodo) && destroVuoto(nodo));
	}

	void visitaPreOrdine(Posizione nodo) const
	{
		if (!binAlberoVuoto())
		{
			cout << leggiNodo(nodo) << " ";

			if (!sinistroVuoto(nodo))
			{
				visitaPreOrdine(figlioSinistro(nodo));
			}

			if (!destroVuoto(nodo))
			{
				visitaPreOrdine(figlioDestro(nodo));
			}
		}
	}

	void visitaPostOrdine(Posizione nodo) const
	{
		if (!binAlberoVuoto())
		{
			if (!sinistroVuoto(nodo))
			{
				visitaPostOrdine(figlioSinistro(nodo));
			}

			if (!destroVuoto(nodo))
			{
				visitaPostOrdine(figlioDestro(nodo));
			}

			cout << leggiNodo(nodo) << " ";
		}
	}

	void visitaSimmetrica(Posizione nodo) const
	{
		if (!binAlberoVuoto())
		{
			if (!sinistroVuoto(nodo))
			{
				visitaSimmetrica(figlioSinistro(nodo));
			}

			cout << leggiNodo(nodo) << " ";

			if (!destroVuoto(nodo))
			{
				visitaSimmetrica(figlioDestro(nodo));
			}
		}
	}
		
	int altezza(Posizione nodo) const
	{
		if (destroVuoto(nodo) && sinistroVuoto(nodo))
		{
			return 0;
		}

		int u = 0;

		if (!destroVuoto(nodo))
		{
			u = altezza(figlioDestro(nodo));
		}

		int v = 0;

		if (!sinistroVuoto(nodo))
		{
			v = altezza(figlioSinistro(nodo));
		}

		if (u > v)
		{
			return ++u;
		}
		else
		{
			return ++v;
		}
	}

	void stampa() const
	{
		if (!binAlberoVuoto())
		{
			visitaPreOrdine(binRadice());
		}
		else
		{
			cout << "[]";
		}

		cout << endl;
	}

	int contaNodi(Posizione nodo)
	{
		int risultato, sommaNodiSinistri, sommaNodiDestri;

		if (sinistroVuoto(nodo) && destroVuoto(nodo))
		{
			risultato = 1;
			scriviEtichetta(risultato, nodo);
		}
		else
		{
			if (!sinistroVuoto(nodo))
			{
				contaNodi(figlioSinistro(nodo));
				sommaNodiSinistri = leggiEtichetta(figlioSinistro(nodo));
			}
			else
			{
				sommaNodiSinistri = 0;
			}

			if (!destroVuoto(nodo))
			{
				contaNodi(figlioDestro(nodo));
				sommaNodiDestri = leggiEtichetta(figlioDestro(nodo));
			}
			else
			{
				sommaNodiDestri = 0;
			}

			risultato = sommaNodiSinistri + sommaNodiDestri + 1;
		}

		scriviEtichetta(risultato, nodo);
		return risultato;
	}
};

#endif