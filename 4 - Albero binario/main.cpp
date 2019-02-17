#include "AlberoBinarioPuntatore.h"

#include <iostream>
using namespace std;

int main()
{
	AlberoBinarioPuntatore<char> tree = AlberoBinarioPuntatore<char>();
	AlberoBinarioPuntatore<char> temp = AlberoBinarioPuntatore<char>();
	tree.stampa();
	tree.insBinRadice(new NodoPuntatore<char>('h'));

	temp.insBinRadice(new NodoPuntatore<char>('a'));
	tree.insFiglioSinistro(tree.binRadice(), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('c'));
	tree.insFiglioDestro(tree.binRadice(), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('d'));
	tree.insFiglioSinistro(tree.figlioSinistro(tree.binRadice()), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('l'));
	tree.insFiglioDestro(tree.figlioSinistro(tree.binRadice()), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('o'));
	tree.insFiglioSinistro(tree.figlioDestro(tree.figlioSinistro(tree.binRadice())),
		&temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('q'));
	tree.insFiglioDestro(tree.figlioDestro(tree.figlioSinistro(tree.binRadice())),
		&temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('c'));
	tree.insFiglioDestro(tree.binRadice(), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('p'));
	tree.insFiglioSinistro(tree.figlioDestro(tree.binRadice()), &temp);

	temp = AlberoBinarioPuntatore<char>();
	temp.insBinRadice(new NodoPuntatore<char>('s'));
	tree.insFiglioDestro(tree.figlioDestro(tree.binRadice()), &temp);

	cout << "Visita in preordine:\n";
	tree.visitaPreOrdine(tree.binRadice());
	cout << endl << "Visita in postordine:\n";
	tree.visitaPostOrdine(tree.binRadice());
	cout << endl << "Visita in simmetrica:\n";
	tree.visitaSimmetrica(tree.binRadice());


	cout << endl << "Altezza: " << tree.altezza(tree.binRadice()) << endl;
	cout << endl << "Numero nodi: " << tree.contaNodi(tree.binRadice()) << endl;

	AlberoBinarioPuntatore<char>* second;
	second = new AlberoBinarioPuntatore<char>(tree);
	tree.cancSottoBinAlbero(tree.figlioDestro(tree.binRadice()));

	second->stampa();
	cout << endl;
	tree.stampa();

	int stop;
	cin >> stop;
	return 0;
}