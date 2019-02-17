#ifndef CODA_PRIORITA_PUNTATORE_H
#define CODA_PRIORITA_PUNTATORE_H

#include "AlberoBinarioPuntatore.h"
#include "CodaPrioritaAstratta.h"

template<typename Dati>
class CodaPrioritaPuntatore: public AlberoBinarioPuntatore<Dati>,
	public CodaPrioritaAstratta<Dati>
{
public:
	CodaPrioritaPuntatore()
	{
		creaPrioriCoda();
	}

	// ALGEBRA FONDAMENTALE
	void creaPrioriCoda()
	{
		albero = nullptr;
		ultimoNodo = nullptr;
	}

	bool prioriCodaVuota() const
	{
		return binAlberoVuoto();
	}

	void inserisci(Dati valore)
	{
		AlberoBinarioPuntatore* alberoTemporaneo = new AlberoBinarioPuntatore();
		alberoTemporaneo->insBinRadice(new NodoPuntatore<Dati>(valore));

		// l'albero è vuoto
		if (prioriCodaVuota())
		{
			insBinRadice(new NodoPuntatore<Dati>(valore));
			ultimoNodo = albero;
		}
		// l'albero ha solo la radice
		else if (albero == ultimoNodo)
		{
			insFiglioSinistro(albero, alberoTemporaneo);
			ultimoNodo = figlioSinistro(albero);
		}
		// l'ultimo nodo inserito è un figlio sinistro
		else if (figlioSinistro(binPadre(ultimoNodo)) == ultimoNodo)
		{
			insFiglioDestro(binPadre(ultimoNodo), alberoTemporaneo);
			ultimoNodo = figlioDestro(binPadre(ultimoNodo));
		}
		else
		{
			NodoPuntatore<Dati>* nodoTemporaneo = ultimoNodo;

			while (binPadre(nodoTemporaneo))
			{
				if (figlioDestro(binPadre(nodoTemporaneo)) == nodoTemporaneo)
				{
					nodoTemporaneo = binPadre(nodoTemporaneo);
				}
			}

			if (nodoTemporaneo != binRadice())
			{
				nodoTemporaneo = figlioDestro(binPadre(nodoTemporaneo));

				while (!foglia(nodoTemporaneo))
				{
					nodoTemporaneo = figlioSinistro(nodoTemporaneo);
					insFiglioSinistro(nodoTemporaneo, alberoTemporaneo);
				}
			}

			ultimoNodo = figlioSinistro(nodoTemporaneo);
		}

		NodoPuntatore<Dati>* nodoTemporaneo = ultimoNodo;

		while (nodoTemporaneo != binRadice() &&
		        (leggiNodo(nodoTemporaneo) < leggiNodo(binPadre(nodoTemporaneo))))
		{
			Dati valoreTemporaneo = leggiNodo(nodoTemporaneo);
			scriviNodo(leggiNodo(binPadre(nodoTemporaneo)), nodoTemporaneo);
			scriviNodo(valoreTemporaneo, binPadre(nodoTemporaneo));
		}
	}

	Dati min() const
	{
		return leggiNodo(binRadice());
	}

	void cancellaMin()
	{
		if (!prioriCodaVuota())
		{
			NodoPuntatore<Dati>* nodoTemporaneo = ultimoNodo;

			while (nodoTemporaneo != albero
			        && figlioSinistro(binPadre(nodoTemporaneo))
			        == nodoTemporaneo)
			{
				nodoTemporaneo = binPadre(nodoTemporaneo);
			}

			while (figlioDestro(nodoTemporaneo)
			        || figlioSinistro(nodoTemporaneo))
			{
				if (figlioDestro(nodoTemporaneo))
				{
					nodoTemporaneo = figlioDestro(nodoTemporaneo);
				}
				else
				{
					nodoTemporaneo = figlioSinistro(nodoTemporaneo);
				}
			}

			scriviNodo(leggiNodo(nodoTemporaneo), albero);
		}

		if (ultimoNodo != albero)
		{
			Dati valoreTemporaneo;
			NodoPuntatore<Dati>* nodo = albero;

			while (figlioSinistro(nodo)
			        && leggiNodo(nodo) > leggiNodo(figlioSinistro(nodo)))
			{
				valoreTemporaneo = leggiNodo(nodo);
				scriviNodo(leggiNodo(figlioSinistro(nodo)), nodo);
				scriviNodo(valoreTemporaneo, figlioSinistro(nodo));
			}

			nodo = albero;

			if (figlioDestro(nodo))
			{
				while (figlioDestro(nodo)
				        && leggiNodo(nodo) > leggiNodo(figlioDestro(nodo)))
				{
					valoreTemporaneo = leggiNodo(nodo);
					scriviNodo(leggiNodo(figlioDestro(nodo)), nodo);
					scriviNodo(valoreTemporaneo, figlioDestro(nodo));
				}
			}
		}
	}

private:
	NodoPuntatore<Dati>* ultimoNodo;
};

#endif
