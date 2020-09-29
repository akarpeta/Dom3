#pragma once
#include "windows.h"
#include <iostream>
#include <commdlg.h>
#include <stdlib.h>
#include <string>
#include "lista.h"
#include "dom.h"

// GUI po odkomentowaniu
/*
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#define ID_PRZYCISK_1	100
#define ID_PRZYCISK_2	101
#define ID_TEXTBOX		102
#define ID_LISTBOX		103
#define ID_PANEL		104
#define ID_PRZYCISK_3	105

#define IDC_MYICON                      2
#define IDD_WINAPIEXAMPLE_DIALOG        102
#define IDS_APP_TITLE                   103
#define IDD_ABOUTBOX                    103
#define IDM_ABOUT                       104
#define IDM_EXIT                        105
#define IDI_WINAPIEXAMPLE               107
#define IDI_SMALL                       108
#define IDC_WINAPIEXAMPLE               109
#define IDR_MAINFRAME                   128
#define IDD_NASZDIALOG                  130
#define IDCANCEL                        1002
#define IDDCANCEL                       1002
#define IDC_PROGRESS1                   1003
#define IDC_SLIDER1                     1004
#define IDC_RADIO1                      1005
#define IDC_RADIO2                      1006
#define IDC_RADIO3                      1007
#define IDC_RADIO4                      1008
#define IDC_STATIC                      -1

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NO_MFC                     1
#define _APS_NEXT_RESOURCE_VALUE        131
#define _APS_NEXT_COMMAND_VALUE         32771
#define _APS_NEXT_CONTROL_VALUE         1006
#define _APS_NEXT_SYMED_VALUE           110
#endif
#endif


using namespace std;

/// 

string nowy_wlasciciel;		///< okreœla nowego w³aœciciela budynku
int nowy_rok;				///< okreœla nowy rok wybudowania budynku
int ilosc_pokoi;			///< okreœla iloœæ pokoi w budynku
int opcja;					///< przechowuje wybran¹ opcjê z g³ównego menu
int opcja2;					///< przechowuje wybran¹ opcjê z pobocznego menu


HWND hButton1, hButton2, hButton3;
HBITMAP hBitmap;
Lista<Dom> lista;
int i = 1;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

// Funkcja do testowania obs³ugi okien wiadomoœci. 
void WINAPI TestMessages()
{
	int ret;
	ret = MessageBox(NULL, "Przyk³adowy tekst", "Przyk³ad WinAPI", MB_YESNOCANCEL | MB_ICONQUESTION);
	switch (ret)
	{
	case IDYES:
		MessageBox(NULL, "Wciœniêto YES", "Przyk³ad WinAPI", MB_OK | MB_ICONEXCLAMATION);
		break;
	case IDNO:
		MessageBox(NULL, "Wciœniêto NO", "Przyk³ad WinAPI", MB_OK | MB_ICONEXCLAMATION);
		break;
	case IDCANCEL:
		MessageBox(NULL, "Wciœniêto Cancel", "Przyk³ad WinAPI", MB_OK | MB_ICONEXCLAMATION);
		break;
	}
}

BOOL GetFilename(char *buf, int len)
{
	OPENFILENAME ofn;       // common dialog box structure
	char *filename = buf;

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filename;


	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	ofn.lpstrTitle = "Wczytaj bitmapê";
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = len;
	ofn.lpstrFilter = "Bitmap\0*.bmp\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Display the Open dialog box. 
	return GetOpenFileName(&ofn);
}

// Funkcja obs³uguj¹ca komunikaty systemu. 
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	}
		break;

	case WM_COMMAND:
		if (wParam == ID_PRZYCISK_1)
		{
			Dom dom;
			lista.dodajElement(dom, 1);
		}
		if (wParam == ID_PRZYCISK_2)
		{
			lista.usunElement(1);
			
		}
		if (wParam == ID_PRZYCISK_3)
		{
			MSG msg;
			char bitmap_name[1024];
			GetFilename(bitmap_name, 1024);
			hBitmap = (HBITMAP)LoadImage(NULL, bitmap_name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			if (hBitmap == NULL)
			{
				MessageBox(NULL, "Pliku z obrazkiem nie znaleziono!", "Error", MB_ICONERROR);
				return 0;
			}
			BOOL fGotMessage;
			while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && fGotMessage != -1)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}

// Rejestracja klasy okna. 
BOOL RegisterWndClass(HINSTANCE hinstance)
{
	WNDCLASSEX wcx;

	wcx.cbSize = sizeof(wcx);				  // wielkoœæ struktury
	wcx.style = CS_HREDRAW | CS_VREDRAW;		  // przerysuj jeœli zmieni siê wielkoœæ
	wcx.lpfnWndProc = MainWndProc;			  // wskaŸnik do procedury obs³ugi okna 
	wcx.cbClsExtra = 0;						  // dodatkowa pamiêæ klasy
	wcx.cbWndExtra = 0;						  // dodatkowa pamiêæ okna
	wcx.hInstance = hinstance;				  // uchwyt do aplikacji
	wcx.hIcon = LoadIcon(NULL,
		IDI_APPLICATION);					  // predefiniowana ikona aplikacji 
	wcx.hCursor = LoadCursor(NULL,
		IDC_ARROW);						      // predefiniowana strza³ka 
	wcx.hbrBackground = (HBRUSH)GetStockObject(
		WHITE_BRUSH);						  // bia³a g¹bka
	wcx.lpszMenuName = "GlowneMenu";	      // nazwa menu 
	wcx.lpszClassName = "GlownaKlasa";		  // nazwa okna 
	wcx.hIconSm = (HICON)LoadImage(hinstance, // ma³a ikonka klasy
		MAKEINTRESOURCE(5),
		IMAGE_ICON,
		GetSystemMetrics(SM_CXSMICON),
		GetSystemMetrics(SM_CYSMICON),
		LR_DEFAULTCOLOR);

	// Zarejestruj klasê!
	return RegisterClassEx(&wcx);
}

LRESULT CALLBACK NewWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		BITMAP bmInfo;
		// stwórz kontekst urz¹dzenia dla bitmapy
		HDC hdcBitmap = CreateCompatibleDC(hdc);

		// do kontekstu urz¹dzenia przypisz nasz¹ bitmapê
		// SelectObject zwraca przypisan¹ wczeœniej do kontekstu domyœln¹ bitmapê
		HBITMAP hOld = (HBITMAP)SelectObject(hdcBitmap, hBitmap);

		// pobierz w³aœciwoœci bitmapy
		GetObject(hBitmap, sizeof(bmInfo), &bmInfo);

		// skopiuj dane z kontekstu urz¹dzenia do kontekstu okna
		BitBlt(hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, hdcBitmap, 0, 0, SRCCOPY);

		// wybierz z powrotem star¹ bitmapê przypisan¹ domyœlnie do hdcBitmap
		SelectObject(hdcBitmap, hOld);

		// usuñ stworzony, niepotrzebny ju¿ kontekst
		DeleteDC(hdcBitmap);

		EndPaint(hwnd, &ps);
	}
		break;
	}

	return 0;
}

BOOL CreateAndShowMainWindow(HINSTANCE hinstance, int nCmdShow)
{
	HWND hwnd;

	hwnd = CreateWindow(
		"GlownaKlasa",        // nazwa klasy okna 
		"Dom",      // tytu³ okna
		WS_OVERLAPPEDWINDOW,  // styl okna
		CW_USEDEFAULT,        // domyœlna pozycja horyzontalna  
		CW_USEDEFAULT,        // domyœlna pozycja wektykalna
		400,				  // szerokoœæ okna
		600,                  // wysokoœæ okna 
		(HWND)NULL,           // w³aœciciel okna (tutaj brak)
		(HMENU)NULL,          // menu oka
		hinstance,            // uchwyt do instancji aplikacji
		(LPVOID)NULL);        // parametry przes³ane od okna (brak)

	if (!hwnd)
		return FALSE;

	hButton1 = CreateWindowEx(0,		// styl kontrolki
		"BUTTON",						// klasa kontrolki - tu trzeba wpisaæ okreœlony typ!
		"Dodaj",					// to co pojawi siê na przycisku
		WS_CHILD | WS_VISIBLE,			// typ kontrolki - potomna okna i widoczna
		50, 50, 100, 30,				// pozycja i rozmiar kontrolki
		hwnd,							// uchwyt do okna w którym ma byæ kontrolka
		(HMENU)ID_PRZYCISK_1,			// uchwyt do menu lub identyfikator (dla WS_CHILD)
		hinstance,						// uchwyt do instancji aplikacji
		NULL);							// parametry przes³ane od kontrolki (brak)

	hButton2 = CreateWindowEx(0,		// styl kontrolki
		"BUTTON",						// klasa kontrolki - tu trzeba wpisaæ okreœlony typ!
		"Usuń",					// to co pojawi siê na przycisku
		WS_CHILD | WS_VISIBLE,			// typ kontrolki - potomna okna i widoczna
		50, 90, 100, 30,				// pozycja i rozmiar kontrolki
		hwnd,							// uchwyt do okna w którym ma byæ kontrolka
		(HMENU)ID_PRZYCISK_2,			// uchwyt do menu lub identyfikator (dla WS_CHILD)
		hinstance,						// uchwyt do instancji aplikacji
		NULL);							// parametry przes³ane od kontrolki (brak)

	hButton3 = CreateWindowEx(0,		// styl kontrolki
		"BUTTON",						// klasa kontrolki - tu trzeba wpisaæ okreœlony typ!
		"Dodaj zdjęcie",					// to co pojawi siê na przycisku
		WS_CHILD | WS_VISIBLE,			// typ kontrolki - potomna okna i widoczna
		50, 130, 100, 30,				// pozycja i rozmiar kontrolki
		hwnd,							// uchwyt do okna w którym ma byæ kontrolka
		(HMENU)ID_PRZYCISK_3,			// uchwyt do menu lub identyfikator (dla WS_CHILD)
		hinstance,						// uchwyt do instancji aplikacji
		NULL);

	HWND hText = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT",
		NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		50, 180, 130, 30,
		hwnd, (HMENU)ID_TEXTBOX, hinstance, NULL);

	HWND hListBox = CreateWindowEx(WS_EX_CLIENTEDGE, "LISTBOX",
		NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_AUTOVSCROLL,
		220, 50, 100, 120, hwnd, (HMENU)ID_LISTBOX, hinstance, NULL);

	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2000");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2001");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2002");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2003");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2004");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2005");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2006");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2007");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2008");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2009");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2010");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2011");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2012");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2013");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2014");
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM) "2015");


	HWND hPanel = CreateWindowEx(WS_EX_CLIENTEDGE, "STATIC",
		NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		50, 250, 300, 300,
		hwnd, (HMENU)ID_PANEL, hinstance, NULL);

	SetWindowLongPtr(hPanel, GWLP_WNDPROC, (LONG)NewWndProc);

	ShowWindow(hwnd, nCmdShow);		// ustawienie stanu okna
	UpdateWindow(hwnd);				// aktualizacja zawartoœci okna
	// wysy³a wiadomoœæ WM_PAINT

	return TRUE;
}


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR    lpCmdLine,
	int       nCmdShow)
{
	MSG msg;
	// TestMessages();		// odkomentuj aby przetestowaæ okna wiadomoœci

	if (!RegisterWndClass(hInstance))
		return FALSE;

	if (!CreateAndShowMainWindow(hInstance, nCmdShow))
		return FALSE;

	BOOL fGotMessage;
	while ((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0 && fGotMessage != -1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	DeleteObject(hBitmap);

	return msg.wParam;
}

*/

int main()
{
	Lista<Dom> lista;

	int opcja; ///<zmienna używana do wyboru opcje w menu
	int obiekt = 0;

	//Menu programu
	opcja = 99;
	do {
		switch (opcja)
		{
		case 99:
			cout << "MENU PROGRAMU" << endl;
			cout << "-------------------------------" << endl;
			cout << "Wybierz opcje:" << endl;
			cout << "1: Zmien obiekt" << endl;
			cout << "2: Wyswietl elementy" << endl;
			cout << "3: Dodaj obiekt do listy w wybranym miejscu" << endl;
			cout << "4: Usun wybrany obiekt" << endl;
			cout << "5: Wysietl czas powstania elementu" << endl;
			cout << "8: Testowanie operatora przypisania" << endl;
			cout << "9: Testowanie kopiowania listy" << endl;
			cout << "0: Zamknij program" << endl;
			cout << "-------------------------------" << endl;
			cout << "Opcja: ";
			cin >> opcja;
			break;
		case 1:
			system("cls");
			if (lista.rozmiar() == 0)
				cout << "Brak elementow na liscie!" << endl;
			else
			{
				int numer;
				cout << "Podaj pozycje elementu, ktory chcesz zmienic: ";
				cin >> numer;
				if (numer < 1 || numer > lista.rozmiar())
				{
					cout << "Podano nieprawidlowy numer. " << endl;
				}
				else
				{
					string nazwisko;
					cout << "Podaj nazwisko nowego wlasciciela:" << endl;
					cin >> nazwisko;
					Wezel<Dom> *tmp = lista.zwrocWskaznikWezla(numer);
					tmp->obiekt.zmienWlasciciela(nazwisko);
				}
			}
			opcja = 99;
			break;
		case 2:
		{
			system("cls");
			cout << "Liczba obiektow: " << lista.rozmiar() << endl;
			lista.wyswietlWszystkieObiekty();
			//fflush(stdin);
		//	cout << endl << "Nacisnij klawisz [ENTER] aby kontynuowac." << endl;
		//	cin.get();
		//	system("cls");
			opcja = 99;
			break;
		}
		case 3:
		{
			system("cls");
			int numer;
			cout << "Podaj pozycje, na ktorej ma byc nowy element: ";
			cin >> numer;
			if (numer < 1 || numer > lista.rozmiar()+1)
			{
				cout << "Podano nieprawidlowy numer. " << endl;
			}
			else
			{
				Dom dom;
				lista.dodajElement(dom, numer);
			}
			opcja = 99;
			break;
		}
			
		case 4:
		{
			system("cls");
			int numer;
			cout << "Podaj pozycje elementu, ktory chcesz usunac: " << endl;
			cin >> numer;
			if (numer < 1 || numer > lista.rozmiar())
			{
				cout << "Podano nieprawidlowy numer. " << endl;
			}
			else
			{
				lista.usunElement(numer);
			}
			opcja = 99;
			break;
		}
		case 5:
		{
			system("cls");
			int numer;
			cout << "Podaj pozycje elementu, ktorego czas chcesz wywolac: " << endl;
			cin >> numer;

			if (numer < 1 || numer > lista.rozmiar() )
			{
				cout << "Podano nieprawidlowy numer. " << endl;
			}
			else
			{
				Wezel<Dom> *tmp = lista.zwrocWskaznikWezla(numer);
				cout << "Czas trwania obiektu: ";
				lista.zwrocCzas(tmp);
			}
			opcja = 99;
			break;
		}
		
		case 8:
		{
			system("cls");
			Lista<Dom> lista1;
			Dom dom, dom1;
			lista1.dodajElement(dom, 1);
			lista1.dodajElement(dom, 2);
			cout << "Stworzono liste z 2 elementami" << endl;
			lista1.wyswietlWszystkieObiekty();
			cout << "Przypisano te sama liste" << endl;
			lista1 = lista1;
			cout << "Przypisano liscie liste wczesniejsza" << endl;
			lista1 = lista;
			lista1.wyswietlWszystkieObiekty();
			opcja = 99;
			break;
		}

		case 9:
		{
			Lista<Dom>lista1 (lista);
			system("cls");
			cout << "Skopiowano liste" << endl;
			lista1.wyswietlWszystkieObiekty();
			opcja = 99;
			break;
		}
		default:
		{
			system("cls");
			cout << "Wybrano niepoprawna opcje." << endl;
			opcja = 99;
		}
			
		}
	} while (opcja != 0);
	return 0;
}
