#include <iostream>
#include "piwnica.h"

using namespace std;

Piwnica::Piwnica()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny Piwnica" << endl;
#endif
	dlugosc = 4;
	szerokosc = 4;
	powierzchnia = dlugosc*szerokosc;
	poziom_zapelnienia = 0.2;
}

Piwnica::Piwnica(float dlugosc, float szerokosc, float poziom_zapelnienia)
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor Piwnica" << endl;
#endif
	this->dlugosc = dlugosc;
	this->szerokosc = szerokosc;
	powierzchnia = dlugosc*szerokosc;
	this->poziom_zapelnienia = poziom_zapelnienia;
}


void Piwnica::wyswietlInformacje()
{
	cout << "Dlugosc piwnicy: " << dlugosc << endl;
	cout << "Szerokosc piwnicy: " << szerokosc << endl;
	cout << "Powierzchnia piwnicy: " << powierzchnia << endl;
	cout << "Poziom zapelnienia piwnicy: " << poziom_zapelnienia << endl << endl;
}

void Piwnica::zmienPoziomZapelnienia(float nowe_zapelnienie)
{
	poziom_zapelnienia = nowe_zapelnienie;
}

bool Piwnica::operator == (const Piwnica &piwnica)
{
	if (piwnica.dlugosc == dlugosc && piwnica.szerokosc == szerokosc && piwnica.poziom_zapelnienia == poziom_zapelnienia)
		return true;
	else
		return false;
}

bool Piwnica::operator != (const Piwnica &piwnica)
{
	if (piwnica.dlugosc != dlugosc || piwnica.szerokosc != szerokosc || piwnica.poziom_zapelnienia != poziom_zapelnienia)
		return true;
	else
		return false;
}

Piwnica & Piwnica::operator += (const Piwnica &piwnica)
{
	poziom_zapelnienia += piwnica.poziom_zapelnienia;
	return *this;
}

Piwnica & Piwnica::operator -= (const Piwnica &piwnica)
{
	if (poziom_zapelnienia > piwnica.poziom_zapelnienia)
		poziom_zapelnienia -= piwnica.poziom_zapelnienia;
	return *this;
}

Piwnica::~Piwnica()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor Piwnica" << endl;
#endif
}
