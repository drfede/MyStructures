#ifndef BST_PUNTATORE_H
#define BST_PUNTATORE_H

#include "BSTAstratto.h"
#include "AlberoBinarioPuntatore.h"

template<typename Dati>
class BSTPuntatore : public BSTAstratto<Dati, NodoPuntatore<Dati>*>,
    public AlberoBinarioPuntatore<Dati>
{
public:
    typedef typename NodoPuntatore<Dati>* Posizione;

    BSTPuntatore()
    {
        albero = nullptr;
    }

    // ALGEBRA FONDAMENTALE
    Posizione appartiene(Dati valore) const
    {
        Posizione nodoTemporaneo = binRadice();

        while (nodoTemporaneo != nullptr)
        {
            if (leggiNodo(nodoTemporaneo) == valore)
            {
                return nodoTemporaneo;
            }

            if (leggiNodo(nodoTemporaneo) > valore)
            {
                nodoTemporaneo = figlioSinistro(nodoTemporaneo);
            }

            if (leggiNodo(nodoTemporaneo) < valore)
            {
                nodoTemporaneo = figlioDestro(nodoTemporaneo);
            }
        }

        return nullptr;
    }

    void aggiungiNodo(Dati valore)
    {
        Posizione nodo = new NodoPuntatore<Dati>;

        scriviNodo(valore, nodo);

        Posizione nodoTemporaneo = binRadice();

        if (binAlberoVuoto())
        {
            albero = nodo;
            return;
        }

        while (!binAlberoVuoto())
        {
            if (leggiNodo(nodoTemporaneo) > valore)
            {
                if (figlioSinistro(nodoTemporaneo) == nullptr)
                {
                    AlberoBinarioPuntatore<Dati> albero;
                    albero.insBinRadice(nodo);
                    insFiglioSinistro(nodoTemporaneo, &albero);
                    return;
                }
                else
                {
                    nodoTemporaneo = figlioSinistro(nodoTemporaneo);
                }
            }

            if (leggiNodo(nodoTemporaneo) < valore)
            {
                if (figlioDestro(nodoTemporaneo) == nullptr)
                {
                    AlberoBinarioPuntatore<Dati> albero;
                    albero.insBinRadice(nodo);
                    insFiglioDestro(nodoTemporaneo, &albero);
                    return;
                }

                else
                {
                    nodoTemporaneo = figlioDestro(nodoTemporaneo);
                }
            }
        }
    }

    void rimuoviNodo(Dati valore)
    {
        Posizione nodo = appartiene(valore);

        if (nodo)
        {
            // Caso 1: il nodo è una foglia
            if (!figlioSinistro(nodo) && !figlioDestro(nodo))
            {
                if (figlioSinistro(binPadre(nodo)) == nodo)
                {
                    insFiglioSinistro(binPadre(nodo), nullptr);
                }
                else
                {
                    insFiglioDestro(binPadre(nodo), nullptr);
                }
            }

            // Caso 2: il nodo ha un solo figlio
            else if ((figlioSinistro(nodo) && !figlioDestro(nodo))
                     || (figlioDestro(nodo) && !figlioSinistro(nodo)))
            {
                Posizione nodoTemporaneo = binPadre(nodo);

                if (figlioSinistro(nodoTemporaneo) == nodo)
                {
                    nodoTemporaneo->
                    scriviFiglioSinistro((!figlioSinistro(nodo)) ?
                                         figlioDestro(nodo) : figlioSinistro(nodo));
                    (figlioSinistro(nodoTemporaneo))->
                    scriviPadre(nodoTemporaneo);
                }
                else
                {
                    nodoTemporaneo->scriviFiglioDestro
                    ((figlioSinistro(nodo) == nullptr) ? figlioDestro(nodo)
                     : figlioSinistro(nodo));
                    (figlioDestro(nodoTemporaneo))->
                    scriviPadre(nodoTemporaneo);
                }

                delete nodo;
            }

            // Caso 3: il nodo ha entrambi i figli
            else if (figlioSinistro(nodo) && figlioDestro(nodo))
            {
                Posizione nodoTemporaneo = figlioDestro(nodo);

                while (figlioSinistro(nodoTemporaneo))
                {
                    nodoTemporaneo = figlioSinistro(nodoTemporaneo);
                }

                scriviNodo(leggiNodo(nodoTemporaneo), nodo);

                if (figlioDestro(nodoTemporaneo))
                {
                    binPadre(nodoTemporaneo)->
                    scriviFiglioDestro(figlioDestro(nodoTemporaneo));
                    figlioDestro(binPadre(nodoTemporaneo))->
                    scriviPadre(binPadre(nodoTemporaneo));
                }

                delete nodoTemporaneo;
            }
        }
    }

    Dati minimo() const
    {
        Posizione nodoTemporaneo = binRadice();

        while (!sinistroVuoto(nodoTemporaneo))
        {
            nodoTemporaneo = figlioSinistro(nodoTemporaneo);
        }

        return leggiNodo(nodoTemporaneo);
    }

    Dati massimo() const
    {
        Posizione nodoTemporaneo = binRadice();

        while (!destroVuoto(nodoTemporaneo))
        {
            nodoTemporaneo = figlioDestro(nodoTemporaneo);
        }

        return leggiNodo(nodoTemporaneo);
    }
};

#endif
