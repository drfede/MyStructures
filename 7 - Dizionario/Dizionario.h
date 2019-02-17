#ifndef DIZ_H
#define DIZ_H
#include <iostream>
#include "Hash.h"
#include "listap.h"
#include "Entry.h"

template<typename K, typename E> class Dizionario {
// E=tipo elemento, K=tipo chiave
typedef Entry<K,E> entry;

public:
Dizionario(unsigned int); // costruttore
~Dizionario(); // distruttore

bool vuoto();
// restituisce true se il dizionario � vuoto

bool appartiene(const K& );
// restituisce true se l'elemento appartiene al dizionario

E recupera(const K&);
// restituisce l'elemento corrispondente alla chiave (se esiste)

void inserisci(const K&, const E&);
// inserisce un elemento nel dizionario

void cancella(const K&);
// elimina l'elemento

unsigned int dimensione();
// restituisce il numero elementi del dizionario

void stampa();

private:
unsigned int H(const K&);
// calcola il valore hash dell'elemento object
unsigned int lunghezza; // lunghezza massima del dizionario
unsigned int nelementi; // elementi presenti in un certo istante nel dizionario
circLista< Entry <K,E> >* table; // liste di trabocco per le entry
};

template <typename K, typename E> Dizionario<K,E>::Dizionario(unsigned int n){
lunghezza = n;
nelementi = 0;
table = new circLista< entry >[lunghezza];
}

template <typename K, typename E> Dizionario<K,E>::~Dizionario()
{ delete[] table; }

template<typename K, typename E> bool Dizionario<K,E>::vuoto(){
return (nelementi == 0);
};

template<typename K, typename E> bool Dizionario<K,E>::appartiene(const K& key){
Cella<entry>* iter;
bool trovato = false;
unsigned int pos = H(key);
iter = table[pos].primoLista();
while (!table[pos].finelista(iter) && !trovato){
if (key == table[pos].leggilista(iter).getKey()) 
trovato = true;
iter = table[pos].succlista(iter);
}
return(trovato);
};

template<typename K, typename E> E Dizionario<K,E>::recupera(const K& key){
Cella <entry>* iter;
bool trovato = false;
E elem;
unsigned int pos = H(key);
iter = table[pos].primoLista();
while (!table[pos].finelista(iter) && !trovato){
if (key == table[pos].leggilista(iter).getKey())
{ 
   trovato = true;
   elem=table[pos].leggilista(iter).getValue();
}
iter = table[pos].succlista(iter);
}
return(elem);
};

template<typename K, typename E> void Dizionario<K,E>::inserisci(const K& chiave, const E& element){
entry e(chiave,element);
Cella <entry>* posizione=table[H(chiave)].primoLista();                  
table[H(chiave)].inslista(e,posizione);
nelementi++;
};

template<typename K, typename E> void Dizionario<K,E>::cancella(const K& chiave){
Cella <entry>* iter;
bool trovato = false;
unsigned int pos = H(chiave);
iter = table[pos].primoLista();
while (!table[pos].finelista(iter) && !trovato){
if (chiave == table[pos].leggilista(iter).getKey())
   trovato = true;
else
    iter = table[pos].succlista(iter);
}
if (trovato)
{
   table[pos].canclista(iter);
   nelementi--;
}
};

template<typename K, typename E> unsigned int Dizionario<K,E>::H(const K& chiave){
return (hash(chiave) % lunghezza);
}

template<typename K, typename E> unsigned int  Dizionario<K,E>::dimensione(){
return nelementi;
}

template<typename K, typename E> void Dizionario<K,E>::stampa(){
for (int i=0;i<lunghezza;i++)
{
    table[i].stampaLista();    
}
};

#endif // DIZ_H
