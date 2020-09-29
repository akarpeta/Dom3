#pragma once
#include <iostream>
#include <time.h>
#include "dom.h"

using namespace std;

template <class TYP>
struct Wezel
{
	TYP obiekt;
	Wezel *poprzedni;
	clock_t czas;
};


template <class TYP>
class Lista
{
private:
	Wezel <TYP> *koniec;
	int liczba_elementow;
public:
	Lista();
	Lista(const Lista &lista);
	~Lista();
	void dodajElement(const Dom &obiekt, int numer);
	void usunElement(int numer);
	Wezel<TYP>* zwrocWskaznikWezla(int numer) const;
	void zwrocCzas(Wezel <Dom> *obiekt);
	void wyswietlWszystkieObiekty();
	int rozmiar();

	Lista& operator = (const Lista & lista);
	Wezel<TYP>* operator[](int i);
};

#include "lista.cpp"