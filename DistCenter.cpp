////////////////////
// Piotr Wróbel 120B
////////////////////
// DistCenter . cpp
////////////////////

#include <iostream>
#include "inne.h"
#include "generatory.h"
//#include "pracownik.h" lab 2-3
#include "towar.h"
#include "magazyn.h"
#include "menu.h"
#include "tir.h"


using namespace std;

int main() {

	setup();
	Magazyn* magazyn = new Magazyn();
	/*magazyn->wyswietl_pracownika();
	magazyn->print()*/
	//Pracownik** pracownicy = nullptr; lab 2-3
	//size_t p_rozmiar = 3; lab 2-3
	Towar* towary = nullptr;
	size_t t_rozmiar = 100; size_t t_zapisane = 3;
	//stworz_pracownika(pracownicy, p_rozmiar); lab 2-3
	//inicjalizuj_gen_pracownika(pracownicy, p_rozmiar); lab 2-3
	stworz_towar(towary, t_rozmiar);
	inicjalizuj_gen_towar(towary, t_zapisane); //inicjalizuj_gen_towar(towary, t_rozmiar);
	//menu(pracownicy, p_rozmiar, towary, t_rozmiar, t_zapisane); lab 2-3
	menu(magazyn, towary, t_rozmiar, t_zapisane);

	return 0;
}
