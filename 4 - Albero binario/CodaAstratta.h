#ifndef CODAASTRATTA_H
#define CODAASTRATTA_H

#include <iostream>
using namespace std;

/**
    Una coda è un tipo astratto che consente di rappresentare una sequenza di
    elementi con accesso agli estremi: è possibile aggiungere elementi ad un
    estremo, il fondo, e togliere elementi dall'altro estremo, la testa.

    Può essere vista come un caso speciale di lista in cui il primo elemento
    inserito è anche il primo ad essere rimosso (FIFO) e non è possibile accedere
    ad alcun elemento che non sia quello in fondo alla coda.

* */
template<typename Dati>
class CodaAstratta
{
public:
	// ALGEBRA FONDAMENTALE
	/**
	    CREACODA() -> coda Q

	    Post: Q' = <>

	    Inizializza la coda.

	* */
	virtual void creaCoda() = 0;

	/**
	    CODAVUOTA(coda Q) -> boolean b

	    Post: b = true se Q = <>
	        b = false altrimenti

	    Controlla se la coda è vuota.

	    @return true se la coda è vuota, false altrimenti

	* */
	virtual bool codaVuota() const = 0;

	/**
	    LEGGICODA(coda Q) -> tipoelem a

	    Pre: Q = a_1, a_2, ..., a_n, n >= 1
	    Post: a = a_1

	    Restituisce il valore memorizzato in cima alla coda.

	    @return valore memorizzato in cima alla coda

	* */
	virtual Dati leggiCoda() const = 0;

	/**
	    FUORICODA(coda Q) -> coda Q'

	    Pre: Q = a_1, a_2, ..., a_n n >= 1
	    Post: Q' = a_2, a_3, ..., a_n    se n >=1
	        Q' = <> se n = 1

	    Rimuove il valore in cima alla coda.

	* */
	virtual void fuoriCoda() = 0;

	/**
	    INCODA(tipoelem a, coda Q) -> coda Q'

	    Pre: Q = a_1, a_2, ..., a_n  n >= 0
	    Post: Q' = a, a_1, a_2, ..., a_n

	    Aggiunge un valore in fondo alla coda.

	    @param valore valore da memorizzare in fondo alla coda

	* */
	virtual void inCoda(Dati valore) = 0;

	// ALTRI METODI
	/**
	    Calcola e restituisce il numero di valori memorizzati nella coda.

	    @return dimensione della coda

	* */
	int leggiDimensione()
	{
		return dimensione;
	}

	/**
	    Scorre la coda dall'elemento in cima a quello in fondo e la stampa.

	* */
	void stampa()
	{
		Dati* vettore = new Dati[leggiDimensione()];
		int dim = leggiDimensione();

		for (int i = 0; i < dim; i++)
		{
			Dati valoreTemporaneo = leggiCoda();
			vettore[i] = valoreTemporaneo;
			fuoriCoda();
		}

		for (int i = 0; i < dim; i++)
		{
			cout << vettore[i] << endl;
			inCoda(vettore[i]);
		}
	}

protected:
	int dimensione;
};

#endif
