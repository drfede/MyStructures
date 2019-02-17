#include "GrafoMatrice.h"

#include <string>

using namespace std;

int main()
{
	GrafoMatrice<string, double> G;

	NodoGrafo a, b, c, d, e, f, g, h;

	G.insNodo(a);
	G.scriviEtichetta(a, "a");
	G.insNodo(b);
	G.scriviEtichetta(b, "b");
	G.insNodo(c);
	G.scriviEtichetta(c, "c");
	G.insNodo(d);
	G.scriviEtichetta(d, "d");
	G.insNodo(f);
	G.scriviEtichetta(f, "f");

	G.insNodo(g);
	G.scriviEtichetta(g, "g");
	h.scriviIDnodo(999);

	G.insArco(a, b, 1);
	G.insArco(a, d, 1);
	G.insArco(b, c, 1);
	G.insArco(f, g, 1);
	G.insArco(g, d, 1);
	G.insArco(c, a, 1);
	G.insArco(c, d, 1);
	G.insArco(c, f, 1);
	G.insArco(c, g, 1);

	cout << "NumNodi " << G.leggiNumeroNodi();
	cout << "\nNumArchi " << G.leggiNumeroArchi();

	G.cancNodo(f);

	cout << "\nNumNodi " << G.leggiNumeroNodi() << endl;

	if (G.esisteArco(b, a))
	{
		cout << "BINGO!\n";
	}

	GrafoMatrice<string, double>::ListaNodi L = G.adiacenti(a);

	GrafoMatrice<string, double>::ListaNodiPosizione p;

	cout << "Adiacenti di a --> ";
	p = L.primoLista();

	for (int i = 0; i < L.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L.leggiLista(p))) << " ";
		p = L.succLista(p);
	}

	GrafoMatrice<string, double>::ListaNodi L2 = G.adiacenti(b);
	cout << "\nAdiacenti di b --> ";
	p = L2.primoLista();

	for (int i = 0; i < L2.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L2.leggiLista(p))) << " ";
		p = L2.succLista(p);
	}

	GrafoMatrice<string, double>::ListaNodi L3 = G.adiacenti(c);
	cout << "\nAdiacenti di c --> ";
	p = L3.primoLista();

	for (int i = 0; i < L3.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L3.leggiLista(p))) << " ";
		p = L3.succLista(p);
	}

	GrafoMatrice<string, double>::ListaNodi L4 = G.adiacenti(d);
	cout << "\nAdiacenti di d --> ";
	p = L4.primoLista();

	for (int i = 0; i < L4.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L4.leggiLista(p))) << " ";
		p = L4.succLista(p);
	}

	GrafoMatrice<string, double>::ListaNodi L5 = G.adiacenti(f);

	cout << "\nAdiacenti di f --> ";
	p = L5.primoLista();

	for (int i = 0; i < L5.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L5.leggiLista(p))) << " ";
		p = L5.succLista(p);
	}

	GrafoMatrice<string, double>::ListaNodi L6 = G.adiacenti(g);

	cout << "\nAdiacenti di g --> ";
	p = L6.primoLista();

	for (int i = 0; i < L6.leggiDimensione(); i++)
	{
		cout << G.leggiEtichetta(*(L6.leggiLista(p))) << " ";
		p = L6.succLista(p);
	}

	cout << "\nVisita in profondita':\n";
	G.visitaProfondita(b);

	cout << endl;

	int stop;
	cin >> stop;

	return 0;
}

