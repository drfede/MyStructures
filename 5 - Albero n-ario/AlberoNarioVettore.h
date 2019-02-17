#ifndef ALBERO_NARIO_VETTORE_H
#define ALBERO_NARIO_VETTORE_H

#include "AlberoNarioAstratto.h"
#include "NodoVettoreAlbero.h"

template<typename Dati>
class AlberoNarioVettore
{
public:
	typedef int* Posizione;

	AlberoNarioVettore()
	{
		creaAlbero();
	};

    // ALGEBRA FONDAMENTALE
	void creaAlbero()
	{
		DIMENSIONE_MASSIMA = 100;
		
        nodi = 0;

		albero = new NodoVettoreAlbero<Dati>[DIMENSIONE_MASSIMA];

		for (int i = 0; i< DIMENSIONE_MASSIMA; i++)
		{
			albero[i].scriviUsato(false);
			albero[i].leggiListaFigli()->creaLista();
		}
	}

	bool alberoVuoto() const
	{
		return !nodi;
	}

	void insRadice(Posizione nodo)
	{
		if (alberoVuoto())
		{
			radiceAlbero = new int(0);
			albero[*radiceAlbero].scriviUsato(true);
			nodi++;
		}
	}
	
    Posizione radice() const
	{
		return radiceAlbero;
	}

	Posizione padre(Posizione nodo) const
	{
		typename ListaVettore<Dati>::Posizione figlio;

		int posizione;
		
        for (int i = 0; i < DIMENSIONE_MASSIMA; i++)
		{
			if (!albero[i].leggiListaFigli()->listaVuota())
			{
				figlio = albero[i].leggiListaFigli()->primoLista();
				
				while (!albero[i].leggiListaFigli()->fineLista(figlio))
				{
					if (albero[i].leggiListaFigli()->leggiLista(figlio) == *nodo)
					{
						return new int(i);
					}
					figlio = albero[i].leggiListaFigli()->succLista(figlio);
				}
			}
		}

		return new int(-1);
	}

	bool foglia(Posizione nodo) const
	{
		return(albero[*nodo].leggiListaFigli()->listaVuota());
	}

	Posizione primoFiglio(Posizione nodo) const
	{
		if (!foglia(nodo))
		{
			return albero[*nodo].leggiListaFigli()->primoLista();
		}
	}
	
	bool ultimoFratello(Posizione nodo) const
	{
		typename ListaVettore<Dati>::Posizione nodoTemporaneo;
		Posizione posizione = padre(nodo);

		nodoTemporaneo = albero[*posizione].leggiListaFigli()->primoLista();
		
		while (!albero[*posizione].leggiListaFigli()->fineLista(
        albero[*posizione].leggiListaFigli()->succLista(nodoTemporaneo)))
			nodoTemporaneo = albero[*posizione].leggiListaFigli()->
                    succLista(nodoTemporaneo);
		return (nodo == albero[*posizione].leggiListaFigli()->
                leggiLista(nodoTemporaneo));
	}
	
	Posizione succFratello(Posizione nodo) const
	{
		if (!ultimoFratello(nodo))
		{
			typename ListaVettore<Dati>::Posizione nodoTemporaneo;
			Posizione posizione = padre(nodo);
            
			nodoTemporaneo = albero[*posizione].leggiListaFigli()->primoLista();
			while (!albero[*posizione].leggiListaFigli()->
                    fineLista(nodoTemporaneo))
			{
				if (albero[*posizione].leggiListaFigli()->
                        leggiLista(nodoTemporaneo) == nodo)
					return (albero[*posizione].leggiListaFigli()->
					leggiLista(albero[*posizione].leggiListaFigli()->
					succLista(nodoTemporaneo)));
				nodoTemporaneo = albero[*posizione].leggiListaFigli()->
                        succLista(nodoTemporaneo);
			}
		}
		else return nullptr;
	}
	
	void insPrimoSottoAlbero(Posizione nodo, Dati nuovoValore)
	{
		int i;

		for (i = 0; i < DIMENSIONE_MASSIMA && 
            albero[i].leggiUsato() == true; i++);
		
        if (i < DIMENSIONE_MASSIMA)
		{
			albero[i].scriviUsato(true);
			albero[i].scriviValore(nuovoValore);
			albero[*nodo].leggiListaFigli()->insLista(i, albero[*nodo].
                leggiListaFigli()->primoLista());
		}
	}
	
	void insSottoAlbero(Posizione nodo, Dati nuovoValore)
	{
		// cerca una posizione libera
		int i;
		for (i = 0; i < DIMENSIONE_MASSIMA &&
			    albero[i].leggiUsato() == true; i++)
		if (i<DIMENSIONE_MASSIMA)
		{
			albero[i].scriviUsato(true);
			albero[i].scriviValore(nuovoValore);
			Posizione posizione = padre(nodo);
			
            ListaVettore<Dati>::Posizione figlio = 
                    albero[*posizione].leggiListaFigli()->primoLista();
			
            bool trovato = false;
			while (!albero[*posizione].leggiListaFigli()->fineLista(figlio) 
                    && !trovato)
			{
				if (albero[*posizione].leggiListaFigli()->
                        leggiLista(figlio) == *nodo)
					trovato = true;
				figlio = albero[*posizione].leggiListaFigli()->succLista(figlio);
			}
			albero[*posizione].leggiListaFigli()->insLista(i, figlio);
		}
	}
	
	void cancSottoAlbero(Posizione nodo)
	{
		typename ListaVettore<Dati>::Posizione nodoTemporaneo;
		
        if (!foglia(nodo))
		{
			while (!albero[*nodo].leggiListaFigli()->listaVuota())
			{
				cancSottoAlbero(albero[*nodo].leggiListaFigli()->primoLista());
			}
		}
		if (*radice()!=*nodo)
		{
			Posizione posizione = padre(nodo);
			nodoTemporaneo = albero[*posizione].leggiListaFigli()->primoLista();

			while (albero[*posizione].leggiListaFigli()->
                    leggiLista(nodoTemporaneo) != *nodo)
				nodoTemporaneo = albero[*posizione].leggiListaFigli()->
                        succLista(nodoTemporaneo);
			albero[*posizione].leggiListaFigli()->cancLista(nodoTemporaneo);
		}
		albero[*nodo].scriviUsato(false);
	}

	Dati leggiNodo(Posizione nodo) const
	{
		return(albero[*nodo].leggiValore());
	}

	void scriviNodo(Posizione nodo, Dati nuovoValore)
	{
		albero[*nodo].scriviValore(nuovoValore);
	}
	
    // ALTRI METODI
	void stampa() const
	{
		cout << "\n{";
		for (int i = 0; i < DIMENSIONE_MASSIMA; i++)
		{
			if (albero[i].leggiUsato())
			{
				cout << "\n  " << leggiNodo(new int(i)) << ":  ";
				if (!foglia(new int(i)))
				{
					typename ListaVettore<int*>::Posizione figlio = 
                            albero[i].leggiListaFigli()->primoLista();
					while (!albero[i].leggiListaFigli()->fineLista(figlio))
					{
						cout << leggiNodo(figlio) << " ";
						figlio = albero[i].leggiListaFigli()->succLista(figlio);
					}
				}
			}

		}
		cout << "\n}\n";
	}


private:
	int DIMENSIONE_MASSIMA;
	
	NodoVettoreAlbero<Dati> *albero;
	
    Posizione radiceAlbero;

	int nodi;
};

#endif
