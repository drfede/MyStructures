#include "CodaPuntatore.h"

int main()
{
	CodaPuntatore<int> C;

	C.inCoda(1);
	C.inCoda(2);
	C.inCoda(3);
	C.inCoda(4);

	C.stampa();

	int stop;
	cin >> stop;

	return 0;
}



