#include <iostream>
#include <string>

using namespace std;
/// Klasa stwarzaj¹ca podobiekt klasy Dom
class Piwnica
{
private:
	float powierzchnia;			///< okreœla powierzchniê piwnicy
	float dlugosc;				///< okreœla d³ugoœæ piwnicy
	float szerokosc;			///< okreœla szerokoœæ piwnicy
	float poziom_zapelnienia;	///< okreœla poziom zape³nienia piwnicy
public:
	/// Konstruktor domyœlny
	Piwnica();
	/// Konstruktor z parametrami
	/**
	Jako parametry podawane s¹: d³ugoœæ piwnicy, szerokoœæ piwnicy oraz poziom zape³nienia
	\param dlugosc jest d³ugoœci¹ piwnicy
	\param szerokosc jest szerokoœci¹ piwnicy
	\param poziom_zapelnienia jest poziomem zape³nienia piwnicy
	*/
	Piwnica(float dlugosc, float szerokosc, float poziom_zapelnienia);
	/// Destruktor
	~Piwnica();
	/// Funkcja wyœwietlaj¹ca informacje o piwnicy
	void wyswietlInformacje();
	/// Funkcja zmieniaj¹ca poziom zape³nienia piwnicy
	/**
	Jako parametr podawany jest nowy poziom zape³nienia
	\param nowe_zapelnienie jest nowym poziomem zape³nienia piwnicy
	*/
	void zmienPoziomZapelnienia(float nowe_zapelnienie);

	/// Operator ==
	bool operator == (const Piwnica &piwnica);
	/// Operator !=
	bool operator != (const Piwnica &piwnica);
	/// Operator +=
	Piwnica& operator += (const Piwnica &piwnica);
	/// Operator -=
	Piwnica& operator -= (const Piwnica &piwnica);
};

