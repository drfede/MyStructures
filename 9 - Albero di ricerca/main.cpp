#include "BSTPuntatore.h"

int main()
{
	BSTPuntatore<int> a;

	a.aggiungiNodo(49);
	a.aggiungiNodo(22);
	a.aggiungiNodo(17);
	a.aggiungiNodo(20);
	a.aggiungiNodo(82);
	a.aggiungiNodo(57);
	a.aggiungiNodo(88);
	a.aggiungiNodo(94);
	a.aggiungiNodo(91);

	a.stampa();
	a.rimuoviNodo(22);
	a.stampa();

	cout << endl << "Minimo: " << a.minimo() << endl << endl;
	cout << "Massimo: " << a.massimo() << endl << endl;

	int stop;

	cin >> stop;

	return 0;
}
