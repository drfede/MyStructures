#include "PilaVettore.h"

int main()
{
	PilaVettore<int> pila;

	pila.inPila(1);
	pila.inPila(2);
	pila.inPila(3);
	pila.inPila(4);

	pila.stampa();

	PilaVettore<int> b = PilaVettore<int>(pila);

	pila.fuoriPila();

	cout << endl;
	b.stampa();

	int stop;
	cin >> stop;

	return 0;
}