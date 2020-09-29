#include <iostream>
#include "domownicy.h"

using namespace std;

Domownicy::Domownicy()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny Domownicy" << endl;
#endif
	liczba_mezczyzn = 2;
	liczba_kobiet = 2;
	liczba_domownikow = liczba_kobiet + liczba_mezczyzn;
	srednia_wieku = 30;
}

Domownicy::Domownicy(int liczba_mezczyzn, int liczba_kobiet, float srednia_wieku)
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor Domownicy" << endl;
#endif
	this->liczba_mezczyzn = liczba_mezczyzn;
	this->liczba_kobiet = liczba_kobiet;
	liczba_domownikow = liczba_kobiet + liczba_mezczyzn;
	this->srednia_wieku = srednia_wieku;
}

void Domownicy::wyswietlInformacje()
{
	cout << "Liczba domownikow: " << liczba_domownikow << endl;
	cout << "Liczba mezczyzn: " << liczba_mezczyzn << endl;
	cout << "Liczba kobiet: " << liczba_kobiet << endl;
	cout << "Srednia wieku domownikow: " << srednia_wieku << endl << endl;
}
void Domownicy::zwiekszLiczbeDomownikow(int wiek, string plec)
{
	srednia_wieku = (srednia_wieku*liczba_domownikow + wiek) / (liczba_domownikow + 1);
	if (plec == "mezczyzna")
		liczba_mezczyzn++;
	else if (plec == "kobieta")
		liczba_kobiet++;

	liczba_domownikow++;
}

bool Domownicy::operator == (const Domownicy &domownicy)
{
	if (domownicy.liczba_kobiet == liczba_kobiet && domownicy.liczba_mezczyzn == liczba_mezczyzn && domownicy.srednia_wieku == srednia_wieku)
		return true;
	else
		return false;
}

bool Domownicy::operator != (const Domownicy &domownicy)
{
	if (domownicy.liczba_kobiet != liczba_kobiet || domownicy.liczba_mezczyzn != liczba_mezczyzn || domownicy.srednia_wieku != srednia_wieku)
		return true;
	else
		return false;
}

Domownicy & Domownicy::operator ++ (int)
{
	srednia_wieku = (srednia_wieku*liczba_domownikow + 20) / (liczba_domownikow + 1);
	liczba_domownikow++;
	liczba_mezczyzn++;
	return *this;
}

Domownicy & Domownicy::operator -- (int)
{
	if (liczba_domownikow>0)
		liczba_domownikow--;
	if (liczba_mezczyzn>0)
		liczba_mezczyzn--;
	else
		liczba_kobiet--;
	return *this;
}

Domownicy::~Domownicy()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor Domownicy" << endl;
#endif
}
