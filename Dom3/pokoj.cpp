#include <iostream>
#include "pokoj.h"

using namespace std;

Pokoj::Pokoj()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny Pokoj" << endl;
#endif
	dlugosc = 4;
	szerokosc = 4;
	powierzchnia = dlugosc*szerokosc;
	przeznaczenie = "Sypialnia";
	podloga = "Drewno";
	kolor_scian = "Bialy";
}

Pokoj::Pokoj(float dlugosc, float szerokosc, string przeznaczenie, string podloga, string kolor_scian)
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor Pokoj" << endl;
#endif
	this->dlugosc = dlugosc;
	this->szerokosc = szerokosc;
	powierzchnia = dlugosc*szerokosc;
	this->przeznaczenie = przeznaczenie;
	this->podloga = podloga;
	this->kolor_scian = kolor_scian;
}

void Pokoj::wyswietlInformacje()
{
	cout << "Dlugosc pokoju: " << dlugosc << endl;
	cout << "Szerokosc pokoju: " << szerokosc << endl;
	cout << "Powierzchnia pokoju: " << powierzchnia << endl;
	cout << "Przeznaczenie pokoju: " << przeznaczenie << endl;
	cout << "Rodzaj podlogi pokoju: " << podloga << endl;
	cout << "Kolor scian pokoju: " << kolor_scian << endl << endl;
}

void Pokoj::zmienPrzeznaczenie(string nowe_przeznaczenie)
{
	przeznaczenie = nowe_przeznaczenie;
}

void Pokoj::malowanie(string nowy_kolor_scian)
{
	kolor_scian = nowy_kolor_scian;
}

bool Pokoj::operator == (const Pokoj &pokoj)
{
	if (pokoj.dlugosc == dlugosc && pokoj.szerokosc == szerokosc && pokoj.przeznaczenie == przeznaczenie && pokoj.podloga == podloga && pokoj.kolor_scian == kolor_scian)
		return true;
	else
		return false;
}

bool Pokoj::operator != (const Pokoj &pokoj)
{
	if (pokoj.dlugosc != dlugosc || pokoj.szerokosc != szerokosc || pokoj.przeznaczenie != przeznaczenie || pokoj.podloga != podloga || pokoj.kolor_scian != kolor_scian)
		return true;
	else
		return false;
}

float Pokoj::zwrocPowierzchnie()
{
	return powierzchnia;
}

Pokoj::~Pokoj()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor Pokoj" << endl;
#endif
}
