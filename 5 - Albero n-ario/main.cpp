#include "AlberoNarioVettore.h"

int main()
{
    AlberoNarioVettore<int> albero1, albero2;

    albero1.creaAlbero();
    albero1.insRadice(new int(1));

    albero2.insRadice(new int(2));
    albero1.insPrimoSottoAlbero(albero1.radice(), &albero2);

    albero2.insRadice(new int(3));
    albero1.insSottoAlbero(albero1.primoFiglio(albero1.radice()), &albero2);

    albero2.insRadice(new int(4));
    albero1.insSottoAlbero(albero1.succFratello(albero1.primoFiglio(
                               albero1.radice())), &albero2);

    albero2.insRadice(new int(5));
    albero1.insPrimoSottoAlbero(albero1.primoFiglio(
                                    albero1.radice()), &albero2);


    albero1.visitaPreOrdine(albero1.radice());

    cout << endl << "Profondita: " <<
         albero1.profonditaMassima(albero1.radice()) << endl;

    albero1.cancSottoAlbero(albero1.primoFiglio(albero1.radice()));

    albero1.visitaPreOrdine(albero1.radice());

    int stop;
    cin >> stop;

    return 0;
}