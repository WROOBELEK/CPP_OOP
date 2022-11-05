////////////////////
// towar . cpp
////////////////////

#include <iostream>
#include <string>
#include "towar.h"
#include "generatory.h"

using namespace std;

//prototypy klasy Towar
void Towar::setNazwa(string a) { nazwa = a; }
string Towar::getNazwa() { return nazwa; }

void Towar::setStan(size_t a) { stan = a; }
size_t Towar::getStan() { return stan; }

void Towar::setCena(float a) { cena = a; }
float Towar::getCena() { return cena; }

size_t Towar::getTowarID() { return towar_id; }

//tworzenie Towar
void stworz_towar(Towar*& _towary) {
	_towary = new Towar;
}

void stworz_towar(Towar*& _towary, const size_t rozmiar) { //tego uzywam
	_towary = new Towar[rozmiar];
}

void stworz_towar(Towar**& _towary, const size_t rozmiar) {
	_towary = new Towar * [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		_towary[i] = new Towar;
	}
}

//usuwanie Towaru
void usun_towar(Towar*& _towary) {
	delete _towary;
	_towary = nullptr;
}

void usun_towar(Towar*& _towary, const size_t rozmiar) {
	delete[] _towary;
	_towary = nullptr;
}

void usun_towar(Towar**& _towary, size_t& rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete _towary[i];
	}
	delete[] _towary;
	_towary = nullptr;
	rozmiar = 0;
}

//usuwanie po indeksie
void usun_towar(Towar*& _towary, size_t& zapisane, size_t index) { //tego uzywam
	if (index + 1 <= zapisane) {
		for (size_t i = index; i < zapisane; i++) {
			_towary[i].setNazwa(_towary[i + 1].getNazwa());
			_towary[i].setStan(_towary[i + 1].getStan());
			_towary[i].setCena(_towary[i + 1].getCena());
		}
		_towary[zapisane - 1].setNazwa("");
		_towary[zapisane - 1].setStan(NULL);
		_towary[zapisane - 1].setCena(NULL);
		zapisane--;
	}
	else {
		cout << "ERROR: Index jest nieprawid³owy !" << endl;
		cin.ignore();
		while (getchar() != '\n');
	}
}

void usun_towar(Towar**& _towary, size_t& rozmiar, size_t index) {
	if (index < rozmiar) {
		Towar** temp = new Towar * [rozmiar - 1];
		short int j{ -1 };
		for (size_t i = 0; i < rozmiar; ++i)
			if (i != index) {
				++j;
				temp[j] = _towary[i];
			}
		delete[] _towary;
		_towary = temp;
		--rozmiar;
	}
	else {
		cout << "ERROR: Index jest nieprawid³owy !" << endl;
		cin.ignore();
		while (getchar() != '\n');
	}
}

//dodawanie Towar
void dodaj_towar(Towar**& _towary, size_t& rozmiar) {
	Towar** temp = new Towar * [rozmiar + 1];
	if (rozmiar == 0) {
		temp[rozmiar] = new Towar;
	}
	else {
		for (size_t i = 0; i < rozmiar; i++)
			temp[i] = _towary[i];
		temp[rozmiar] = new Towar;
		delete[] _towary;
	}
	_towary = temp;
	rozmiar++;
}

//inicjalizacja Towar (ostatni pusty indeks)
void inicjalizuj_towar(Towar* _towary, size_t& zapisane, string marka, string typ, float cena, size_t stan) { //tego uzywam
	//_towary[i]->Towar_id = GeneratorLiczba(1, 100);
	_towary[zapisane].setNazwa(marka + " " + typ);
	_towary[zapisane].setStan(stan);
	_towary[zapisane].setCena(cena);
	zapisane++;
}

void inicjalizuj_towar(Towar** _towary, const size_t rozmiar, string marka, string typ, float cena, size_t stan) {
	size_t i = rozmiar - 1;
	//_towary[i]->Towar_id = GeneratorLiczba(1, 100);
	_towary[i]->setNazwa(marka + " " + typ);
	_towary[i]->setStan(stan);
	_towary[i]->setCena(cena);
}

void wyswietl_towar(Towar* _towary, const size_t zapisane) {
	cout << "--- Towary ---" << endl;
	for (int i = 0; i < zapisane; i++) {
		cout << "ID: " << _towary[i].getTowarID() << endl;
		cout << "Nazwa: " << _towary[i].getNazwa() << endl;
		cout << "Cena: " << _towary[i].getCena() << endl;
		cout << "Na stanie: " << _towary[i].getStan() << endl;
		cout << endl << endl;
	}
}

void wyswietl_towar(Towar** _towary, const size_t rozmiar) {
	cout << "--- Towary ---" << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << "ID: " << _towary[i]->getTowarID() << endl;
		cout << "Nazwa: " << _towary[i]->getNazwa() << endl;
		cout << "Cena: " << _towary[i]->getCena() << endl;
		cout << "Na stanie: " << _towary[i]->getStan() << endl;
		cout << endl << endl;
	}
}

void oblicz_wartosc_towarow(Towar* _towary, const size_t zapisane) {
	float suma = 0;
	for (int i = 0; i < zapisane; i++) {
		suma = suma + _towary[i].getCena() * _towary[i].getStan();
	}
	cout << "Wartoœæ towarów na magazynie: " << suma << " z³";
}

//inicjalizacja Towar
void inicjalizuj_gen_towar(Towar* _towary, const size_t rozmiar) {
	string marka[] = { "XLMOTO", "Sledstore", "24MX", "Alpinestars", "Fox", "Bell", "Course", "Acerbis", "Proworks", "Nexx"};
	string typ[] = { "Kask", "Kombinezon", "Rêkawice", "Ochraniacze", "Plecak", "Grip", "Buty", "Komplet", "Kurtka", "Spodnie" };

	for (int i = 0; i < rozmiar; i++) {
		//_towary[i].Towar_id = GeneratorLiczba(1, 100);
		_towary[i].setNazwa(marka[GeneratorLiczba(0, (sizeof(marka) / sizeof(*marka)) - 1)] + " " + typ[GeneratorLiczba(0, (sizeof(typ) / sizeof(*typ)) - 1)]);
		_towary[i].setStan(GeneratorLiczba(1, 10000));
		_towary[i].setCena(GeneratorLiczba(60, 1500));
	}
}

void inicjalizuj_gen_towar(Towar** _towary, const size_t rozmiar) {
	string marka[] = { "XLMOTO", "Sledstore", "24MX", "Alpinestars", "Fox", "Bell", "Course", "Acerbis", "Proworks", "Nexx" };
	string typ[] = { "Kask", "Kombinezon", "Rêkawice", "Ochraniacze", "Plecak", "Grip", "Buty", "Komplet", "Kurtka", "Spodnie" };

	for (int i = 0; i < rozmiar; i++) {
		//_towary[i].Towar_id = GeneratorLiczba(1, 100);
		_towary[i]->setNazwa(marka[GeneratorLiczba(0, (sizeof(marka) / sizeof(*marka)) - 1)] + " " + typ[GeneratorLiczba(0, (sizeof(typ) / sizeof(*typ)) - 1)]);
		_towary[i]->setStan(GeneratorLiczba(1, 10000));
		_towary[i]->setCena(GeneratorLiczba(60, 1500));
	}
}

/* poni¿sze funkcje dzia³aj¹ dla STRUKTUR

//inicjalizacja Towara (ostatni pusty indeks)
void inicjalizuj_Towara(Towar** _towary, const size_t rozmiar, string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel) {
	int i = rozmiar - 1;
	_towary[i]->Towar_id = GeneratorLiczba(1, 100);
	_towary[i]->imie = imie;
	_towary[i]->nazwisko = nazwisko;
	_towary[i]->login = GeneratorLogin(_towary[i]->imie, _towary[i]->nazwisko);
	_towary[i]->plec = plec;
	_towary[i]->dzien_ur = dzien_ur;
	_towary[i]->miesiac_ur = miesiac_ur;
	_towary[i]->rok_ur = rok_ur;
	_towary[i]->pesel = GeneratorPesel(_towary[i]->dzien_ur, _towary[i]->miesiac_ur, _towary[i]->rok_ur, _towary[i]->plec);
	_towary[i]->miejscowosc = miejscowosc;
	_towary[i]->ulica = ulica;
	_towary[i]->nr_domu = nr_domu;
	_towary[i]->nr_tel = nr_tel;
	_towary[i]->email = GeneratorEmail(_towary[i]->imie, _towary[i]->nazwisko);
}

//inicjalizacja Towara
void inicjalizuj_gen_Towara(Towar* _towary, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		_towary[i].Towar_id = GeneratorLiczba(1, 100);
		_towary[i].imie = imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)];
		_towary[i].nazwisko = nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)];
		_towary[i].login = GeneratorLogin(_towary[i].imie, _towary[i].nazwisko);
		_towary[i].plec = true;
		_towary[i].dzien_ur = GeneratorLiczba(1, 30);
		_towary[i].miesiac_ur = GeneratorLiczba(1, 12);
		_towary[i].rok_ur = GeneratorLiczba(1950, 2004);
		_towary[i].pesel = GeneratorPesel(_towary[i].dzien_ur, _towary[i].miesiac_ur, _towary[i].rok_ur, _towary[i].plec);
		_towary[i].miejscowosc = miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)];
		_towary[i].ulica = ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)];
		_towary[i].nr_domu = GeneratorLiczba(1, 100);
		_towary[i].nr_tel = "+48 123 456 789";
		_towary[i].email = GeneratorEmail(_towary[i].imie, _towary[i].nazwisko);
	}
}

void inicjalizuj_gen_Towara(Towar** _towary, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		_towary[i]->Towar_id = GeneratorLiczba(1, 100);
		_towary[i]->imie = imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)];
		_towary[i]->nazwisko = nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)];
		_towary[i]->login = GeneratorLogin(_towary[i]->imie, _towary[i]->nazwisko);
		_towary[i]->plec = true;
		_towary[i]->dzien_ur = GeneratorLiczba(1, 30);
		_towary[i]->miesiac_ur = GeneratorLiczba(1, 12);
		_towary[i]->rok_ur = GeneratorLiczba(1950, 2004);
		_towary[i]->pesel = GeneratorPesel(_towary[i]->dzien_ur, _towary[i]->miesiac_ur, _towary[i]->rok_ur, _towary[i]->plec);
		_towary[i]->miejscowosc = miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)];
		_towary[i]->ulica = ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)];
		_towary[i]->nr_domu = GeneratorLiczba(1, 100);
		_towary[i]->nr_tel = "+48 123 456 789";
		_towary[i]->email = GeneratorEmail(_towary[i]->imie, _towary[i]->nazwisko);
	}
}

void wyswietl_Towara(Towar** _towary, const size_t rozmiar) {
	cout << "--- Pracownicy ---" << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << _towary[i]->Towar_id << endl;
		cout << _towary[i]->imie << endl;
		cout << _towary[i]->nazwisko << endl;
		cout << _towary[i]->login << endl;
		cout << _towary[i]->plec << endl;
		cout << _towary[i]->dzien_ur << endl;
		cout << _towary[i]->miesiac_ur << endl;
		cout << _towary[i]->rok_ur << endl;
		cout << _towary[i]->pesel << endl;
		cout << _towary[i]->miejscowosc << endl;
		cout << _towary[i]->ulica << endl;
		cout << _towary[i]->nr_domu << endl;
		cout << _towary[i]->nr_tel << endl;
		cout << _towary[i]->email << endl;
		cout << endl << endl;
	}
}
*/