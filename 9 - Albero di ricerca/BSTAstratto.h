#ifndef BST_ASTRATTO_H
#define BST_ASTRATTO_H

template<typename Dati, typename Posizione>
class BSTAstratto
{
public:
	virtual Posizione appartiene(Dati valore) const = 0;

	virtual void aggiungiNodo(Dati valore) = 0;

	virtual void rimuoviNodo(Dati valore) = 0;

	virtual Dati minimo() const = 0;

	virtual Dati massimo() const = 0;
};

#endif
