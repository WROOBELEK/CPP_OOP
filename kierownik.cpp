////////////////////
// kierownik . cpp
////////////////////

#include <iostream>
#include <string>
#include "towar.h"

using namespace std;

void zakup_nowy_towar(Towar*& _towary, size_t& zapisane) {
	string marka;
	string typ;
	float wartosc;
	size_t stan;

	system("cls");
	cout << "Podaj markê: "; cin >> marka;
	cout << "Podaj typ: "; cin >> typ;
	cout << "Podaj wartoœæ: "; cin >> wartosc;
	cout << "Podaj iloœæ: "; cin >> stan;

	inicjalizuj_towar(_towary, zapisane, marka, typ, wartosc, stan);
}

void zakup_nowy_towar(Towar**& _towary, size_t& rozmiar) {
	string marka;
	string typ;
	float cena;
	size_t stan;

	system("cls");
	cout << "Podaj markê: "; cin >> marka;
	cout << "Podaj typ: "; cin >> typ;
	cout << "Podaj cenê: "; cin >> cena;
	cout << "Podaj iloœæ: "; cin >> stan;

	dodaj_towar(_towary, rozmiar);
	inicjalizuj_towar(_towary, rozmiar, marka, typ, cena, stan);
}

void utylizuj_towar(Towar*& _towary, size_t& zapisane) {
	int index = 0;
	system("cls");
	cout << "Podaj indeks: "; cin >> index;
	usun_towar(_towary, zapisane, index);
}

void utylizuj_towar(Towar**& _towary, size_t& rozmiar) {
	int index = 0;
	system("cls");
	cout << "Podaj indeks: "; cin >> index;
	usun_towar(_towary, rozmiar, index);
}