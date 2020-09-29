#include <iostream>
#include <string>

using namespace std;
/// Klasa stwarzaj¹ca podobiekt klasy Dom
class Domownicy
{
private:
	int liczba_domownikow;		///< okreœla liczbê domowników
	int liczba_mezczyzn;		///< okreœla liczbê mê¿czyzn
	int liczba_kobiet;			///< okreœla liczbê kobiet
	float srednia_wieku;		///< okreœla œredni¹ wieku domowników
public:
	/// Konstruktor domyœlny
	Domownicy();
	/// Konstruktor z parametrami
	/**
	Jako parametry podawane s¹: liczba mê¿czyzn, liczba kobiet oraz œrednia wieku
	\param liczba_mezczyzn jest liczb¹ mê¿czyzn
	\param liczba_kobiet jest liczb¹ kobiet
	\param srednia_wieku jest œredni¹ wieku domowników
	*/
	Domownicy(int liczba_mezczyzn, int liczba_kobiet, float srednia_wieku);
	/// Destruktor
	~Domownicy();
	/// Funkcja wyœwietlaj¹ca informacje o domownikach
	void wyswietlInformacje();
	/// Funkcja zwiêksza liczbê domowników
	/**
	Jako parametr podawany jest wiek oraz p³eæ nowego domownika
	\param wiek jest wiekiem nowego domownika, plec jest p³ci¹ nowego domownika
	*/
	void zwiekszLiczbeDomownikow(int wiek, string plec);

	/// Operator ==
	bool operator == (const Domownicy &domownicy);
	/// Operator !=
	bool operator != (const Domownicy &domownicy);
	/// Operator ++
	Domownicy& operator ++ (int);
	/// Operator --
	Domownicy& operator -- (int);
};