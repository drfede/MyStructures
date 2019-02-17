#include "ListaPuntatore.h"
#include "libro.h"

int main()
{
	ListaPuntatore<Libro> a;

	ListaPuntatore<Libro>::Posizione temp;

	temp = a.primoLista();
	a.insLista(Libro("LIBROUNO"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBRODUE"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBRODUE"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBROTRE"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBROQUATTRO"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBROCINQUE"), temp);
	a.stampa();
	temp = a.primoLista();
	a.insLista(Libro("LIBROINSERITO"), temp);
	a.stampa();

	cout << "Dimensione: " << a.leggiDimensione() << endl;

	a.stampa();

	cout << "Cancella l'ultimo elemento:\n";
	temp = a.primoLista();

	while (!a.fineLista(temp))
	{
		temp = a.succLista(temp);
	}

	a.cancLista(temp);
	a.stampa();

	cout << "Dimensione: " << a.leggiDimensione() << endl;

	cout << "Cerca: ";
	string x;
	cin >> x;

	if (a.cerca(x))
	{
		cout << "TROVATO\n\n";
	}
	else
	{
		cout << "NON TROVATO\n\n";
	}


	cout << "\n\nRimozione duplicati:\n";
	a.rimuoviDuplicati();
	a.stampa();

	int stop;
	cin >> stop;

	return 0;
}