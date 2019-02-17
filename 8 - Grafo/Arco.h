#ifndef ARCO_H
#define ARCO_H

template<typename Peso, typename Nodo>
class Arco
{
public:
	Arco()
	{
		peso = Peso();

		primoNodo = Nodo();
		secondoNodo = Nodo();
	}

	Arco(Peso nuovoPeso, Nodo nuovoPrimoNodo, Nodo nuovoSecondoNodo)
	{
		scriviPeso(nuovoPeso);

		scriviPrimoNodo(nuovoPrimoNodo);
		scriviSecondoNodo(nuovoSecondoNodo);
	}

	Peso leggiPeso() const
	{
		return peso;
	}

	void scriviPeso(Peso nuovoPeso)
	{
		peso = nuovoPeso;
	}

	Nodo leggiPrimoNodo() const
	{
		return primoNodo;
	}

	void scriviPrimoNodo(Nodo nuovoPrimoNodo)
	{
		primoNodo = nuovoPrimoNodo;
	}

	Nodo leggiSecondoNodo() const
	{
		return secondoNodo;
	}

	void scriviSecondoNodo(Nodo nuovoSecondoNodo)
	{
		secondoNodo = nuovoSecondoNodo;
	}


private:
	Peso peso;

	Nodo primoNodo;
	Nodo secondoNodo;
};

#endif