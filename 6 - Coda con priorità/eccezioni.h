#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <exception>
#include <string>
using namespace std;

class PuntatoreNullo: public exception
{
public:
	PuntatoreNullo(const string m = "Eccezione rilevata: puntatore nullo.") :
			msg(m)
	{
	}
	const char* what()
	{
		return msg.c_str();
	}

private:
	string msg;
};

class AlberoVuoto: public exception
{
public:
	AlberoVuoto(const string m = "Eccezione rilevata: albero vuoto.") :
			msg(m)
	{
	}
	const char* what()
	{
		return msg.c_str();
	}

private:
	string msg;
};

class AlberoPieno: public exception
{
public:
	AlberoPieno(const string m =
			"Eccezione rilevata: dimensione massima raggiunta.") :
			msg(m)
	{
	}
	const char* what()
	{
		return msg.c_str();
	}

private:
	string msg;
};

class RadiceEsistente: public exception
{
public:
	RadiceEsistente(const string m =
			"Eccezione rilevata: radice esistente.") :
			msg(m)
	{
	}
	const char* what()
	{
		return msg.c_str();
	}

private:
	string msg;
};

class NodoEsistente: public exception
{
public:
	NodoEsistente(const string m =
			"Eccezione rilevata: nodo esistente.") :
			msg(m)
	{
	}
	const char* what()
	{
		return msg.c_str();
	}

private:
	string msg;
};

#endif
