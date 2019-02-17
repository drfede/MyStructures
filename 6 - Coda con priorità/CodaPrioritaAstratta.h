#ifndef CODA_PRIORITA_ASTRATTA_H
#define CODA_PRIORITA_ASTRATTA_H


template<typename Dati>
class CodaPrioritaAstratta
{
public:
	// ALGEBRA FONDAMENTALE
	virtual void creaPrioriCoda() = 0;

	virtual bool prioriCodaVuota() const = 0;

	virtual void inserisci(Dati valore) = 0;

	virtual Dati min() const = 0;

	virtual void cancellaMin() = 0;
};

#endif
