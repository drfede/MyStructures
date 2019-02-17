#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>
using namespace std;

class Libro
{
	friend ostream &operator<<(ostream &, const Libro &);

public:
	Libro()
	{
		titolo = "";
	}

	Libro(string t)
	{
		setTitolo(t);
	}

	void setTitolo(string t)
	{
		titolo = t;
	}

	string getTitolo() const
	{
		return (titolo);
	}

	bool operator ==(Libro l)
	{
		return (getTitolo() == l.getTitolo());
	}
private:

	string titolo;
};

ostream &operator<<(ostream &os, const Libro &l)
{
	return os << l.getTitolo();
}

#endif
