#ifndef ALBERO_NARIO_PUNTATORE_H
#define ALBERO_NARIO_PUNTATORE_H

#include "AlberoNarioAstratto.h"
#include "NodoPuntatore.h"

template<typename Dati>
class AlberoNarioPuntatore: public
	AlberoNarioAstratto<Dati, NodoPuntatore<Dati>*>
{
public:
	typedef typename NodoPuntatore<Dati>* Posizione;

	AlberoNarioPuntatore()
	{
		albero = nullptr;
	}

	AlberoNarioPuntatore(const AlberoNarioPuntatore &alberoOriginale)
	{
		albero = copiaSottoAlbero(alberoOriginale.radice());
	}

	// ALGEBRA FONDAMENTALE
	void creaAlbero()
	{
		albero = new NodoPuntatore<Dati>();
	}

	bool alberoVuoto() const
	{
		return (!albero);
	}

	void insRadice(Posizione nodo)
	{
		if (albero)
		{
			nodo->scriviPrimoFiglio(albero->leggiPrimoFiglio());
		}

		albero = nodo;
	}

	Posizione radice() const
	{
		return albero;
	}

	Posizione padre(Posizione nodo) const
	{
		return nodo->leggiPadre();
	}

	bool foglia(Posizione nodo) const
	{
		return (!nodo->leggiPrimoFiglio());
	}

	Posizione primoFiglio(Posizione nodo) const
	{
		return nodo->leggiPrimoFiglio();
	}

	bool ultimoFratello(Posizione nodo) const
	{
		return (!succFratello(nodo));
	}

	Posizione succFratello(Posizione nodo) const
	{
		return nodo->leggiFratelloSuccessivo();
	}

	void insPrimoSottoAlbero(Posizione nodo, AlberoNarioAstratto* ramo)
	{
		AlberoNarioPuntatore* alberoTemporaneo = new AlberoNarioPuntatore();
		alberoTemporaneo->insRadice(copiaSottoAlbero(ramo->radice()));

		alberoTemporaneo->radice()->scriviPadre(nodo);
		nodo->scriviPrimoFiglio(alberoTemporaneo->radice());
	}

	void insSottoAlbero(Posizione nodo, AlberoNarioAstratto* ramo)
	{
		AlberoNarioPuntatore<Dati>* alberoTemporaneo = new AlberoNarioPuntatore();
		alberoTemporaneo->insRadice(copiaSottoAlbero(ramo->radice()));

		alberoTemporaneo->radice()->scriviFratelloSuccessivo(
		    nodo->leggiFratelloSuccessivo());
		nodo->scriviFratelloSuccessivo(alberoTemporaneo->radice());
		alberoTemporaneo->radice()->scriviPadre(nodo->leggiPadre());
	}

	void cancSottoAlbero(Posizione nodo)
	{
		if (nodo != nullptr)
		{
			Posizione nodoTemporaneo = nodo;

			if (nodo == albero)
			{
				albero = nullptr;
			}
			else
			{
				nodoTemporaneo = nodoTemporaneo->leggiPadre();

				if (nodoTemporaneo->leggiPrimoFiglio() == nodo)
				{
					nodoTemporaneo->scriviPrimoFiglio(
					    succFratello(nodo));
				}
				else
				{
					nodoTemporaneo = nodoTemporaneo->leggiPrimoFiglio();

					while (nodoTemporaneo->leggiFratelloSuccessivo() != nodo)
					{
						nodoTemporaneo = succFratello(nodoTemporaneo);
						nodoTemporaneo->scriviFratelloSuccessivo(
						    nodo->leggiFratelloSuccessivo());
					}
				}
			}
		}
	}

	Dati leggiNodo(Posizione nodo) const
	{
		return nodo->leggiValore();
	}

	void scriviNodo(Posizione nodo, Dati valore)
	{
		nodo->scriviValore(valore);
	}

	// ATTRIBUTI
private:
	Posizione albero;
};

#endif
