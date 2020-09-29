#include <iostream>
#include <string>

using namespace std;
/// Klasa stwarzaj¹ca podobiekt klasy Dom
class Pokoj
{
private:
	float powierzchnia;			///< okreœla powierzchniê pokoju
	float dlugosc;				///< okreœla d³ugoœæ pokoju
	float szerokosc;			///< okreœla szerokoœæ pokoju
	string przeznaczenie;		///< okreœla przeznaczeniê pokoju
	string podloga;				///< okreœla pod³ogê pokoju
	string kolor_scian;			///< okreœla kolor œcian pokoju
public:
	/// Konstruktor domyœlny
	Pokoj();
	/// Konstruktor z parametrami
	/**
	Jako parametry podawane s¹: d³ugoœæ pokoju, szerokoœæ pokoju, przeznaczenie pokoju, rodzaj pod³ogi oraz kolor œcian
	\param dlugosc jest d³ugoœci¹ pokoju
	\param szerokosc jest szerokoœci¹ pokoju
	\param przeznaczenie jest przeznaczeniem pokoju
	\param podloga jest rodzajem  pod³ogi
	\param kolor_scian jest pokorem œcian
	*/
	Pokoj(float dlugosc, float szerokosc, string przeznaczenie, string podloga, string kolor_scian);
	/// Destruktor
	~Pokoj();
	/// Funkcja wyœwietlaj¹ca informacje o pokoju
	void wyswietlInformacje();
	/// Funkcja zwracaj¹ca powierzchniê pokoju
	float zwrocPowierzchnie();
	/// Funkcja zmieniaj¹ca przeznaczenie pokoju
	/**
	Jako parametr podawane jest nowe przeznaczenie
	\param nowe_przeznaczenie jest nowym przeznaczeniem pokoju
	*/
	void zmienPrzeznaczenie(string nowe_przeznaczenie);
	/// Funkcja zmieniaj¹ca kolor œcian
	/**
	Jako parametr podawany jest nowy kolor œcian
	\param nowy_kolor_scian jest nowym kolorem œcian
	*/
	void malowanie(string nowy_kolor_scian);

	/// Operator ==
	bool operator == (const Pokoj &pokoj);
	/// Operator !=
	bool operator != (const Pokoj &pokoj);
};
