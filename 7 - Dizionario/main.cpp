#include "Studente.h"
#include "ListaDiTrabocco.h"
#include "TabellaHash.h"

void presente(string matricola, ListaPuntatore<Studente> &l1,
              ListaPuntatore<Studente> &l2)
{
	ListaDiTrabocco<string, Studente> d1(3);
	ListaDiTrabocco<string, Studente> d2(3);
	ListaPuntatore<Studente>::Posizione indiceElemento = l1.primoLista();

	while (!l1.fineLista(indiceElemento))
	{
		d1.inserisci(l1.leggiLista(indiceElemento).getMatricola(),
		             l1.leggiLista(indiceElemento));
		indiceElemento = l1.succLista(indiceElemento);
	}

	if (d1.appartiene(matricola))
	{
		cout << "Studente " << matricola << " presente\n";
		d1.recupera(matricola).stampa();
	}
	else
	{
		indiceElemento = l2.primoLista();

		while (!l2.fineLista(indiceElemento))
		{
			d2.inserisci(l2.leggiLista(indiceElemento).getMatricola(),
			             l2.leggiLista(indiceElemento));
			indiceElemento = l2.succLista(indiceElemento);
		}

		if (d2.appartiene(matricola))
		{
			cout << "Studente " << matricola << " presente\n";
			d2.recupera(matricola).stampa();
		}
		else
		{
			cout << "Studente " << matricola << " assente\n";
		}
	}
}

int conta_1_no_2(ListaPuntatore<Studente> &l1, ListaPuntatore<Studente> &l2)
{
	ListaDiTrabocco<string, Studente> d(3);
	ListaPuntatore<Studente>::Posizione indiceElemento = l2.primoLista();

	while (!l2.fineLista(indiceElemento))
	{
		d.inserisci(l2.leggiLista(indiceElemento).getMatricola(),
		            l2.leggiLista(indiceElemento));
		indiceElemento = l2.succLista(indiceElemento);
	}

	// ho riempito il dizionario
	int counter = 0;
	indiceElemento = l1.primoLista();

	while (!l1.fineLista(indiceElemento))
	{
		if (!d.appartiene(l1.leggiLista(indiceElemento).getMatricola()))
		{
			counter++;
		}

		indiceElemento = l1.succLista(indiceElemento);
	}

	return counter;
}

int main()
{
	ListaPuntatore<Studente> lezione1;
	ListaPuntatore<Studente> lezione2;
	// studenti

	Studente s1("paolo", "rossi", "12354"); // lez1
	Studente s2("mario", "bianchi", "12366"); // lez1
	Studente s3("antonio", "verdi", "12386"); // lez1 + lez2
	Studente s4("pinco", "pallino", "12554"); // lez2
	Studente s5("rosa", "berardi", "14386"); // lez1
	Studente s6("arianna", "longo", "12777"); // lez 2
	Studente s7("anna", "marchesi", "13732"); // lez 2
	Studente s8("giulio", "bernardi", "15690"); // lez1 + lez 2

	// riempiamo la prima lista
	ListaPuntatore<Studente>::Posizione indiceElemento = lezione1.primoLista();
	lezione1.insLista(s1, indiceElemento = lezione1.succLista(indiceElemento));
	lezione1.insLista(s2, indiceElemento = lezione1.succLista(indiceElemento));
	lezione1.insLista(s3, indiceElemento = lezione1.succLista(indiceElemento));
	lezione1.insLista(s5, indiceElemento = lezione1.succLista(indiceElemento));
	lezione1.insLista(s8, indiceElemento = lezione1.succLista(indiceElemento));
	// riempiamo la seconda lista
	indiceElemento = lezione2.primoLista();
	lezione2.insLista(s3, indiceElemento = lezione2.succLista(indiceElemento));
	lezione2.insLista(s4, indiceElemento = lezione2.succLista(indiceElemento));
	lezione2.insLista(s6, indiceElemento = lezione2.succLista(indiceElemento));
	lezione2.insLista(s7, indiceElemento = lezione2.succLista(indiceElemento));
	lezione2.insLista(s8, indiceElemento = lezione2.succLista(indiceElemento));

	// stampo i dati acquisiti
	lezione1.stampa();
	lezione2.stampa();

	presente("13732", lezione1, lezione2);
	presente("13731", lezione1, lezione2);
	presente("12386", lezione1, lezione2);
	cout << "Dopo la prima lezione : " << conta_1_no_2(lezione1, lezione2) << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
