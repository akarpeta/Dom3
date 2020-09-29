#pragma once
#include "pokoj.h"
#include "domownicy.h"
#include "piwnica.h"
#include <vector>

using namespace std;
static int liczba_obiektow = 0;		///< okreœla liczbê obiektów
/// Klasa Dom dziedzicz¹ca po klasie abstrakcyjnej Budynek
class Dom
{
protected:
	int rok_wybudowania;		///< okreœla rok wybudowania budynku
	string nazwisko_wlasciciela;///< okreœla nazwisko w³aœciciela
	vector <Pokoj> pokoj;		///< wektor przechowuj¹cy pokoje
	Domownicy domownicy;		///< domownicy klasy Domownicy
	Piwnica piwnica;			///< piwnica klasy Piwnica
	float powierzchnia;			///< okreœla powierzchniê domu
	int liczba_pokoi;			///< okreœla liczbê pokoi
	string dom_w_stringach;		///< 
public:
	/// Konstruktor domyœlny
	Dom();
	/// Konstruktor z parametrami
	/**
	Jako parametry podawane s¹: rok wybudowania, nazwisko w³aœciciela oraz liczba pokoi
	\param rok_wybudowania jest rokiem wybudowania domu
	\param nazwisko_wlasciciela jest nazwiskiem w³aœciciela domu
	\param liczba_pokoi jest liczb¹ pokoi w domu
	*/
	Dom(int rok_wybudowania, string nazwisko_wlasciciela, int liczba_pokoi);
	/// Destruktor
	~Dom();

	void zmienWlasciciela(string nowy_wlasciciel);
	void zmienRok(int nowy_rok);

	/// Funkcja zwracaj¹ca iloœæ obiektów
	static int iloscObiektow();
	/// Funkcja wyœwietlaj¹ca informacje o domu
	/** Przes³ania funkcjê z klasy abstrakcyjnej Budynek*/
	void wyswietlInformacje();
	/// Funkcja stwarzaj¹ca pokoje
	/**
	Jako parametr podawana jest liczba pokoi
	\param ilosc_pokoi jest iloœci¹ pokoi, które chcemy stworzyæ
	*/
	void stworzPokoje(int ilosc_pokoi);

	/// Operator !=
	bool operator != (const Dom &dom);
	/// Operator >
	bool operator > (const Dom &dom);
	/// Operator <
	bool operator < (const Dom &dom);

	/// Operator []
	Pokoj operator [] (int numer);
	/// Operator string
	operator string ()const;
};