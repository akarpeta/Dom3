#pragma once
#include "lista.h"
#include <iostream>
#include <fstream>

template <class TYP>
Lista<TYP>::Lista()
{
	liczba_elementow = 0;
	koniec = nullptr;
}

template <class TYP>
Lista<TYP>::Lista(const Lista &lista)
{
	for (int i = 1; i <= lista.liczba_elementow; i++)
	{
		Dom dom;
		dodajElement(dom, i);
		Wezel<Dom> *tmp = zwrocWskaznikWezla(i);
		Wezel<Dom> *tmplista = lista.zwrocWskaznikWezla(i);
		tmp->obiekt = tmplista->obiekt;
		tmp->czas = tmplista->czas;
	}
}

template <class TYP>
void Lista<TYP>::dodajElement(const Dom &obiekt, int numer)
{
	Wezel <Dom>*nowy_wezel = new Wezel <TYP> ();
	nowy_wezel->czas = clock() / CLOCKS_PER_SEC;
	nowy_wezel->obiekt = obiekt;
		if (liczba_elementow == 0)
		{
			koniec = nowy_wezel;
		}
		else if (numer == 1)
		{
			zwrocWskaznikWezla(numer)->poprzedni = nowy_wezel;
			nowy_wezel->poprzedni = nullptr;
		}
		else if (numer == liczba_elementow + 1)
		{
			nowy_wezel->poprzedni = koniec;
			koniec = nowy_wezel;
		}
		else
		{
			Wezel<TYP> *tmp;
			tmp = zwrocWskaznikWezla(numer)->poprzedni;
			zwrocWskaznikWezla(numer)->poprzedni = nowy_wezel;
			nowy_wezel->poprzedni = tmp;
		}
		liczba_elementow++;
}

template <class TYP>
void Lista<TYP>::usunElement(int numer)
{
	Wezel<TYP> *tmp;
	if (liczba_elementow <= 0)
	{
		cout << "Brak obiektow" << endl;
		liczba_elementow++;
	}
		
	else if (liczba_elementow == 1)
	{
		koniec = nullptr;
		tmp = zwrocWskaznikWezla(numer);
		delete tmp;
	}
	else if (numer == 1)
	{
		tmp = zwrocWskaznikWezla(numer+1)->poprzedni;
		zwrocWskaznikWezla(numer+1)->poprzedni = nullptr;
		delete tmp;
	}
	else if (numer == liczba_elementow)
	{
		tmp = koniec;
		koniec = tmp->poprzedni;
		delete tmp;
	}
	else
	{
		tmp = zwrocWskaznikWezla(numer + 1)->poprzedni;
		zwrocWskaznikWezla(numer + 1)->poprzedni = tmp->poprzedni;
		delete tmp;
	}
	liczba_elementow--;
}

template <class TYP>
Wezel<TYP>* Lista<TYP>::zwrocWskaznikWezla(int numer) const
{
	Wezel<TYP> *tmp = koniec;

	for (int i = liczba_elementow; i > numer; i--)
	{
		if (tmp == nullptr)
			return nullptr;
		tmp = tmp->poprzedni;
	}
	return tmp;
}

template <class TYP>
void Lista<TYP>::wyswietlWszystkieObiekty()
{
	if (liczba_elementow != 0)
	{
		Wezel<TYP> *tmp;
		for (int i = 1; i <= liczba_elementow; i++)
		{
			tmp = zwrocWskaznikWezla(i);
			
			cout << "Obiekt nr " << i << endl;
			tmp->obiekt.wyswietlInformacje();
		}
	}
	else
		cout << "Brak obiektow." << endl;
}

template <class TYP>
void Lista<TYP>::zwrocCzas(Wezel <Dom> *obiekt)
{
	cout << obiekt->czas << "sek." << endl;
}

template <class TYP>
int Lista<TYP>::rozmiar(){
	return liczba_elementow;
}

template <class TYP>
Lista<TYP>::~Lista()
{	
	while (liczba_elementow > 1)
	{
		if (liczba_elementow < 2)
		{
			delete koniec;
			koniec = nullptr;
		}
		else
		{
			Wezel<TYP> *tmp = koniec;
			koniec = tmp->poprzedni;
			delete tmp;
			tmp = nullptr;
		}
		
		liczba_elementow--;
	}
	delete koniec;
}
/*
template <class TYP>
Lista<TYP>::~Lista()
{
	Wezel<TYP> *tmp;
	while (liczba_elementow > 1)
	{
		tmp = koniec;
		koniec = tmp->poprzedni;
		delete tmp;
		liczba_elementow--;
	}
	delete koniec;
}
*/
template <class TYP>
Lista<TYP>& Lista<TYP>::operator = (const Lista &lista)
{
	Wezel<Dom> *sprawdz = koniec;
	Wezel<Dom> *sprawdzlista = lista.koniec;
	
	if (sprawdz != sprawdzlista)
	{
		int liczba = liczba_elementow;
		for (int i = 1; i <= liczba; i++)
		{
			usunElement(1);
		}
		for (int i = 1; i <= lista.liczba_elementow; i++)
		{
			Dom dom;
			dodajElement(dom, i);
			Wezel<Dom> *tmp = zwrocWskaznikWezla(i);
			Wezel<Dom> *tmplista = lista.zwrocWskaznikWezla(i);
			tmp->obiekt = tmplista->obiekt;
			tmp->czas = tmplista->czas;
		}
	}
	else
		cout << "Domy sa takie same!" << endl << endl;
	return *this;
}

template <class TYP>
Wezel<TYP>* Lista<TYP>::operator[](int i)
{
	if (i < 0 || i >= liczba_elementow)
	{
		cout << "Nie istnieje taki obiekt." << endl;
		return nullptr;
	}
	return zwrocWskaznikWezla(i-1);
}
