#ifndef NODO_GRAFO_H
#define NODO_GRAFO_H

class NodoGrafo
{
public:
	NodoGrafo()
	{
		IDnodo = -1;
	}

	NodoGrafo(int nuovoIDnodo)
	{
		IDnodo = nuovoIDnodo;
	}

	int leggiIDnodo()
	{
		return IDnodo;
	}

	void scriviIDnodo(int nuovoIDnodo)
	{
		IDnodo = nuovoIDnodo;
	}

	bool operator==(NodoGrafo nodo)
	{
		return (leggiIDnodo() == nodo.leggiIDnodo());
	}

private:
	int IDnodo;
};

#endif