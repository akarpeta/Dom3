#include "dom.h"
#include <sstream>

using namespace std;

string nazwa_pliku_d = "dom.txt";

Dom::Dom()
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor domyslny Dom" << endl;
#endif
	rok_wybudowania = 2000;
	nazwisko_wlasciciela = "Nowak";
	liczba_pokoi = 0;
	liczba_obiektow++;
	powierzchnia = 0;
}

void Dom::zmienWlasciciela(string nowy_wlasciciel)
{
	nazwisko_wlasciciela = nowy_wlasciciel;
}

void Dom::zmienRok(int nowy_rok)
{
	rok_wybudowania = nowy_rok;
}

Dom::Dom(int rok_wybudowania, string nazwisko_wlasciciela, int liczba_pokoi)
{
#ifdef _DEBUG
	cout << "Wywolano konstruktor Dom" << endl;
#endif
	int licznik;
	liczba_obiektow++;
	this->liczba_pokoi = liczba_pokoi;
	this->rok_wybudowania = rok_wybudowania;
	this->nazwisko_wlasciciela = nazwisko_wlasciciela;
	for (licznik = 0; licznik<liczba_pokoi; licznik++)
	{
		Pokoj pk;
		pokoj.push_back(pk);
		powierzchnia += pokoj[licznik].zwrocPowierzchnie();
	}
}

int Dom::iloscObiektow()
{
	return liczba_obiektow;
}

void Dom::wyswietlInformacje()
{
	cout << "Wlasciciel: " << nazwisko_wlasciciela << endl;
	cout << "Rok wybudowania: " << rok_wybudowania << endl;
	cout << "Ilosc pokoi: " << liczba_pokoi << endl;
	cout << "Powierzchnia domu: " << powierzchnia << endl << endl;
	piwnica.wyswietlInformacje();
	domownicy.wyswietlInformacje();
	for (int licznik = 0; licznik < liczba_pokoi; licznik++)
		pokoj[licznik].wyswietlInformacje();
}

void Dom::stworzPokoje(int ilosc_pokoi)
{
	int licznik;
	if (ilosc_pokoi > 0)
	{
		for (licznik = 0; licznik<ilosc_pokoi; licznik++)
		{
			Pokoj pk;
			pokoj.push_back(pk);
			powierzchnia += pokoj[licznik].zwrocPowierzchnie();
		}
		liczba_pokoi += ilosc_pokoi;
	}

}

bool Dom::operator != (const Dom &dom)
{
	if (nazwisko_wlasciciela != dom.nazwisko_wlasciciela || rok_wybudowania != dom.rok_wybudowania || liczba_pokoi != dom.liczba_pokoi || piwnica != dom.piwnica || domownicy != dom.domownicy)
	{
		return true;
	}
	for (int i = 0; i<liczba_pokoi; i++)
	{
		if (pokoj[i] != dom.pokoj[i])
			return true;
	}
	return false;
}

bool Dom::operator >(const Dom &dom)
{
	if (powierzchnia > dom.powierzchnia)
		return true;
	else
		return false;
}

bool Dom::operator < (const Dom &dom)
{
	if (powierzchnia < dom.powierzchnia)
		return true;
	else
		return false;
}

Pokoj Dom::operator [] (int numer)
{
	if (numer>0)
		return pokoj[numer - 1];
	else
		return pokoj[0];
}

Dom::operator string ()const
{
	string tymczasowy;
	ostringstream formattedDom;
	formattedDom << liczba_pokoi << "/" << powierzchnia << "/" << rok_wybudowania << "/" << nazwisko_wlasciciela << endl;
	tymczasowy = formattedDom.str();
	return tymczasowy;
}

Dom::~Dom()
{
#ifdef _DEBUG
	cout << "Wywolano destruktor ~Dom" << endl;
#endif
}
