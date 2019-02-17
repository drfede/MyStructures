#include "CodaPrioritaPuntatore.h"

int main()
{
	CodaPrioritaPuntatore<int> a;

	a.inserisci(1);
	a.inserisci(14);
	a.inserisci(8);
	a.inserisci(7);
	a.inserisci(19);
	a.inserisci(57);
	a.inserisci(31);
	a.inserisci(3);
	a.inserisci(50);
	a.inserisci(20);
	a.inserisci(2);
	a.inserisci(6);
	a.inserisci(44);
	a.inserisci(90);
	a.inserisci(100);
	a.inserisci(300);

	a.visitaPreOrdine(a.binRadice());
	cout << endl << endl;

	a.cancellaMin();

	a.visitaPreOrdine(a.binRadice());

	int stop;
	cin >> stop;

	return 0;
}