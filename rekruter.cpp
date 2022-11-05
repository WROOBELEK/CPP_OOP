////////////////////
// rekruter . cpp
////////////////////

#include <iostream>
#include <string>
//#include "pracownik.h" lab 2-3
#include "magazyn.h"

using namespace std;

//void zatrudnij_pracownika(Pracownik**& _pracownicy, size_t& rozmiar) { lab 2-3
void zatrudnij_pracownika(Magazyn* magazyn) {
	string imie;
	string nazwisko;
	bool plec;
	unsigned short dzien_ur;
	unsigned short miesiac_ur;
	unsigned short rok_ur;
	string miejscowosc;
	string ulica;
	unsigned short nr_domu;
	string nr_tel;
	
	system("cls");
	cout << "Podaj imie: "; cin >> imie;
	cout << "Podaj nazwisko: "; cin >> nazwisko;
	cout << "Podaj plec ( 1 - Mê¿czyzna lub 0 - Kobieta ): "; cin >> plec;
	cout << "Podaj dzien urodzenia: "; cin >> dzien_ur;
	cout << "Podaj miesiac urodzenia: "; cin >> miesiac_ur;
	cout << "Podaj rok urodzenia: "; cin >> rok_ur;
	cout << "Podaj miejscowosc: "; cin >> miejscowosc;
	cout << "Podaj ulicê: "; cin >> ulica;
	cout << "Podaj numer domu: "; cin >> nr_domu;
	cout << "Podaj numer telefonu: "; cin >> nr_tel;
	
	// lab 2-3
	/*dodaj_pracownika(_pracownicy, rozmiar);
	inicjalizuj_pracownika(_pracownicy, rozmiar, imie, nazwisko, plec, dzien_ur, miesiac_ur, rok_ur, miejscowosc, ulica, nr_domu, nr_tel); */

	magazyn->dodaj_pracownika();
	magazyn->inicjalizuj_pracownika(imie, nazwisko, plec, dzien_ur, miesiac_ur, rok_ur, miejscowosc, ulica, nr_domu, nr_tel);
}

//void zwolnij_pracownika(Pracownik**& _pracownicy, size_t& rozmiar) { lab 2-3
void zwolnij_pracownika(Magazyn* magazyn) {
	int index = 0;
	system("cls");
	cout << "Podaj indeks: "; cin >> index;
	//usun_pracownika(_pracownicy, rozmiar, index); lab 2-3
	magazyn->usun_pracownika(index);
}