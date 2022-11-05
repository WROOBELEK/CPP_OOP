////////////////////
// menu . cpp
////////////////////

#include <iostream>
#include "rekruter.h"
//#include "pracownik.h" lab 2-3
#include "kierownik.h"
#include "towar.h"
#include "inne.h"
#include "magazyn.h"
#include "tir.h"
#include <vector>
#include "template.h"

using namespace std;

//void menu(Pracownik** _pracownicy, size_t& prozmiar, Towar* _towary, size_t& trozmiar, size_t& tzapisane) { lab 2-3
void menu(Magazyn* magazyn, Towar* _towary, size_t& trozmiar, size_t& tzapisane) {
	unsigned short option;
	bool break_from_nest = false;
	std::vector<Tir*> tablicaTirow;

	while (true) {
		break_from_nest = false;
		system("cls");
		colors('c'); cout << "--- DistCenter.pl ---" << endl; colors('x');
		cout << "1 - Zaloguj jako "; colors('y'); cout << "Rekruter"; colors('x'); cout << endl;
		cout << "2 - Zaloguj jako "; colors('r'); cout << "Kierownik"; colors('x'); cout << endl;
		cout << "3 - Symuluj dzia³anie" << endl;
		cout << "0 - Zamknij program" << endl;
		cout << "> ";
		cin >> option;
		cin.ignore();

		switch (option) {
		case 1: ////////////////////////////////////////////////////////////// rektuter
			while (!break_from_nest) {
				system("cls");
				colors('c'); cout << "--- DistCenter.pl --- ("; colors('y'); cout << "Rekruter"; colors('c'); cout << ") ---" << endl; colors('x');
				cout << "1 - Zatrudnij nowego pracownika" << endl;
				cout << "2 - Zwolnij pracownika" << endl;
				cout << "3 - Wyœwietl listê pracowników" << endl;
				cout << "9 - Wyloguj siê " << endl;
				cout << "> ";
				cin >> option;
				cin.ignore();
				switch (option)
				{
				case 1:
					zatrudnij_pracownika(magazyn);
					//zatrudnij_pracownika(_pracownicy, prozmiar);
					break;
				case 2:
					zwolnij_pracownika(magazyn);
					//zwolnij_pracownika(_pracownicy, prozmiar);
					break;
				case 3:
					system("cls");
					magazyn->wyswietl_pracownika();
					//wyswietl_pracownika(_pracownicy, prozmiar);
					while (getchar() != '\n');
					break;
				case 9:
					break_from_nest = true;
					break;
				default:
					break;
				}
			}
			break;
		case 2: //////////////////////////////////////////////////////////////kierownik
			while (!break_from_nest) {
				system("cls");
				colors('c'); cout << "--- DistCenter.pl --- ("; colors('r'); cout << "Kierownik"; colors('c'); cout << ") ---" << endl; colors('x');
				cout << "1 - Zakup nowy towar" << endl;
				cout << "2 - Utylizuj dany towar" << endl;
				cout << "3 - Wyswietl listê towarów" << endl;
				cout << "4 - Oblicz wartoœæ towarów na magazynie" << endl;
				cout << "5 - Oceñ pracownika" << endl;
				cout << "6 - Zwolnij pracownika" << endl;
				cout << "7 - Wyœwietl listê pracowników" << endl;
				cout << "9 - Wyloguj siê " << endl;
				cout << "> ";
				cin >> option;
				cin.ignore();
				switch (option)
				{
				case 1:
					zakup_nowy_towar(_towary, tzapisane);
					//zakup_nowy_towar(_towary, trozmiar);
					break;
				case 2:
					utylizuj_towar(_towary, tzapisane);
					//utylizuj_towar(_towary, trozmiar);
					break;
				case 3:
					system("cls");
					wyswietl_towar(_towary, tzapisane);
					//wyswietl_towar(_towary, trozmiar);
					while (getchar() != '\n');
					break;
				case 4:
					system("cls");
					oblicz_wartosc_towarow(_towary, tzapisane);
					while (getchar() != '\n');
					break;
				case 5:
					magazyn->ocen_pracownika();
					//ocen_pracownika(_pracownicy, prozmiar);
					break;
				case 6:
					zwolnij_pracownika(magazyn);
					//zwolnij_pracownika(_pracownicy, prozmiar);
					break;
				case 7:
					system("cls");
					magazyn->wyswietl_pracownika();
					//wyswietl_pracownika(_pracownicy, prozmiar);
					while (getchar() != '\n');
					break;
				case 9:
					break_from_nest = true;
					break;
				default:
					break;
				}
			}
			break;
		case 3:
			while (!break_from_nest) {
				system("cls");
				colors('c'); cout << "--- DistCenter.pl --- ("; colors('g'); cout << "Symulacja"; colors('c'); cout << ") ---" << endl; colors('x');
				cout << "1 - TIR" << endl;
				cout << "9 - WyjdŸ" << endl;
				cout << "> ";
				cin >> option;
				cin.ignore();
				switch (option)
				{
				case 1:
					system("cls");
					Tir* tirus;
					if (GeneratorLiczba(0, 1)) {
						tirus = new Dostawa;
					}
					else
						tirus = new Wysylka;
					tablicaTirow.push_back(tirus);

					tablicaTirow[tablicaTirow.size() - 1]->obslugaTira(_towary, tzapisane);
					while (getchar() != '\n');
					break;

				case 9:
					break_from_nest = true;
					break;
				default:
					break;
				}
			}
			break;
		case 0:
			usun(tablicaTirow, tablicaTirow.size());
			tablicaTirow.clear();
			delete magazyn;
			return;
		default:
			break;
		}
	}
}