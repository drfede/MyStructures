#ifndef ALBERO_NARIO_ASTRATTO_H
#define ALBERO_NARIO_ASTRATTO_H

#include <iostream>
using namespace std;

template<typename Dati, typename Posizione>
class AlberoNarioAstratto
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaAlbero() = 0;

		virtual bool alberoVuoto() const = 0;

		virtual void insRadice(Posizione nodo) = 0;

		virtual Posizione radice() const = 0;

		virtual Posizione padre(Posizione nodo) const = 0;

		virtual bool foglia(Posizione nodo) const = 0;

		virtual Posizione primoFiglio(Posizione nodo) const = 0;

		virtual bool ultimoFratello(Posizione nodo) const = 0;

		virtual Posizione succFratello(Posizione nodo) const = 0;

		virtual void insPrimoSottoAlbero(Posizione nodo,
	                                 AlberoNarioAstratto* ramo) = 0;

		virtual void insSottoAlbero(Posizione nodo, AlberoNarioAstratto* ramo) = 0;

		virtual void cancSottoAlbero(Posizione nodo) = 0;

		virtual Dati leggiNodo(Posizione nodo) const = 0;

		virtual void scriviNodo(Posizione nodo, Dati valore) = 0;

	// ALTRI METODI
	void visitaPreOrdine(Posizione nodo) const
	{
		if (nodo)
		{
			Posizione nodoTemporaneo;

			cout << leggiNodo(nodo) << " ";

			if (!foglia(nodo))
			{
				nodoTemporaneo = primoFiglio(nodo);

				while (!ultimoFratello(nodoTemporaneo))
				{
					visitaPreOrdine(nodoTemporaneo);
					nodoTemporaneo = succFratello(nodoTemporaneo);
				}

				visitaPreOrdine(nodoTemporaneo);
			}
		}
	}

	int profonditaMassima(Posizione nodo)
	{
		int profondita = 0;
		int valoreMassimo;
		int valoreCorrente;

		Posizione nodoTemporaneo;
        
		if (foglia(nodo))
		{
			profondita = 0;
		}
		else
        {
			nodoTemporaneo = primoFiglio(nodo);
			valoreMassimo = profonditaMassima(nodoTemporaneo);

			while (!ultimoFratello(nodoTemporaneo))
			{
				nodoTemporaneo = succFratello(nodoTemporaneo);
				valoreCorrente = profonditaMassima(nodoTemporaneo);

				if (valoreMassimo < valoreCorrente)
				{
					valoreMassimo = valoreCorrente;
				}
			}

			profondita = valoreMassimo + 1;
		}

		return profondita;
	}

	Posizione copiaSottoAlbero(Posizione nodo)
	{
		Posizione nodoTemporaneo;

		if (!nodo)
		{
			return nullptr;
		}
		else
		{
			nodoTemporaneo = new NodoPuntatore<Dati>();
			scriviNodo(nodoTemporaneo, leggiNodo(nodo));
			nodoTemporaneo->
                scriviFratelloSuccessivo(copiaSottoAlbero(succFratello(nodo)));
			nodoTemporaneo->
                scriviPrimoFiglio(copiaSottoAlbero(primoFiglio(nodo)));

			Posizione nodoTemporaneo2 = primoFiglio(nodoTemporaneo);

			while (nodoTemporaneo2 != nullptr)
			{
				nodoTemporaneo2->scriviPadre(nodoTemporaneo);
				nodoTemporaneo2 = succFratello(nodoTemporaneo2);
			}

			return nodoTemporaneo;
		}
	}

private:
	int nodi;
};

#endif
