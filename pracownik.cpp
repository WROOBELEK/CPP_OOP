////////////////////
// pracownik . cpp
////////////////////

#include <iostream>
#include <string>
#include "pracownik.h"
#include "generatory.h"

using namespace std;

//prototypy klasy Pracownik
void Pracownik::setImie(string a) { imie = a; }
string Pracownik::getImie() { return imie; }

void Pracownik::setNazwisko(string a) { nazwisko = a; }
string Pracownik::getNazwisko() { return nazwisko; }

void Pracownik::setLogin(string a) { login = a; }
string Pracownik::getLogin() { return login; }

void Pracownik::setPlec(bool a) { plec = a; }
bool Pracownik::getPlec() { return plec; }

void Pracownik::setDzien(unsigned short a) { dzien_ur = a; }
unsigned short Pracownik::getDzien() { return dzien_ur; }

void Pracownik::setMiesiac(unsigned short a) { miesiac_ur = a; }
unsigned short Pracownik::getMiesiac() { return miesiac_ur; }

void Pracownik::setRok(unsigned short a) { rok_ur = a; }
unsigned short Pracownik::getRok() { return rok_ur; }

void Pracownik::setPesel(string a) { pesel = a; }
string Pracownik::getPesel() { return pesel; }

void Pracownik::setMiejscowosc(string a) { miejscowosc = a; }
string Pracownik::getMiejscowosc() { return miejscowosc; }

void Pracownik::setUlica(string a) { ulica = a; }
string Pracownik::getUlica() { return ulica; }

void Pracownik::setNrDomu(unsigned short a) { nr_domu = a; }
unsigned short Pracownik::getNrDomu() { return nr_domu; }

void Pracownik::setNrTel(string a) { nr_tel = a; }
string Pracownik::getNrTel() { return nr_tel; }

void Pracownik::setEmail(string a) { email = a; }
string Pracownik::getEmail() { return email; }

void Pracownik::setOcena(unsigned short a) { ocena = a; }
unsigned short Pracownik::getOcena() { return ocena; }

size_t Pracownik::getPracownik_ID() { return pracownik_id; }

//tworzenie pracownika
void stworz_pracownika(Pracownik*& _pracownicy) {
	_pracownicy = new Pracownik;
}

void stworz_pracownika(Pracownik*& _pracownicy, const size_t rozmiar) {
	_pracownicy = new Pracownik[rozmiar];
}

void stworz_pracownika(Pracownik**& _pracownicy, const size_t rozmiar) {
	_pracownicy = new Pracownik * [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		_pracownicy[i] = new Pracownik;
	}
}

//usuwanie pracownika
void usun_pracownika(Pracownik*& _pracownicy) {
	delete _pracownicy;
	_pracownicy = nullptr;
}

void usun_pracownika(Pracownik*& _pracownicy, const size_t rozmiar) {
	delete[] _pracownicy;
	_pracownicy = nullptr;
}

void usun_pracownika(Pracownik**& _pracownicy, size_t& rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete _pracownicy[i];
	}
	delete[] _pracownicy;
	_pracownicy = nullptr;
	rozmiar = 0;
}

//usuwanie po indeksie
void usun_pracownika(Pracownik**& _pracownicy, size_t& rozmiar, size_t index) {
	if (index < rozmiar) {
		Pracownik** temp = new Pracownik * [rozmiar - 1];
		short int j{ -1 };
		for (size_t i = 0; i < rozmiar; ++i)
			if (i != index) {
				++j;
				temp[j] = _pracownicy[i];
			}
		delete[] _pracownicy;
		_pracownicy = temp;
		--rozmiar;
	}
	else {
		cout << "ERROR: Index jest nieprawid³owy !" << endl;
		cin.ignore();
		while (getchar() != '\n');
	}
}

//dodawanie pracownika
void dodaj_pracownika(Pracownik**& _pracownicy, size_t& rozmiar) {
	Pracownik** temp = new Pracownik * [rozmiar + 1];
	if (rozmiar == 0) {
		temp[rozmiar] = new Pracownik;
	}
	else {
		for (size_t i = 0; i < rozmiar; i++)
			temp[i] = _pracownicy[i];
		temp[rozmiar] = new Pracownik;
		delete[] _pracownicy;
	}
	_pracownicy = temp;
	rozmiar++;
}

//inicjalizacja pracownika (ostatni pusty indeks)
void inicjalizuj_pracownika(Pracownik** _pracownicy, const size_t rozmiar, string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel) {
	size_t i = rozmiar - 1;
	//_pracownicy[i]->pracownik_id = GeneratorLiczba(1, 100);
	_pracownicy[i]->setImie(imie);
	_pracownicy[i]->setNazwisko(nazwisko);
	_pracownicy[i]->setLogin(GeneratorLogin(_pracownicy[i]->getImie(), _pracownicy[i]->getNazwisko()));
	_pracownicy[i]->setPlec(plec);
	_pracownicy[i]->setDzien(dzien_ur);
	_pracownicy[i]->setMiesiac(miesiac_ur);
	_pracownicy[i]->setRok(rok_ur);
	_pracownicy[i]->setPesel(GeneratorPesel(_pracownicy[i]->getDzien(), _pracownicy[i]->getMiesiac(), _pracownicy[i]->getRok(), _pracownicy[i]->getPlec()));
	_pracownicy[i]->setMiejscowosc(miejscowosc);
	_pracownicy[i]->setUlica(ulica);
	_pracownicy[i]->setNrDomu(nr_domu);
	_pracownicy[i]->setNrTel(nr_tel);
	_pracownicy[i]->setEmail(GeneratorEmail(_pracownicy[i]->getImie(), _pracownicy[i]->getNazwisko()));
}

void wyswietl_pracownika(Pracownik** _pracownicy, const size_t rozmiar) {
	cout << "--- Pracownicy ---" << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << _pracownicy[i]->getPracownik_ID() << endl;
		cout << _pracownicy[i]->getImie() << endl;
		cout << _pracownicy[i]->getNazwisko() << endl;
		cout << _pracownicy[i]->getLogin() << endl;
		cout << _pracownicy[i]->getPlec() << endl;
		cout << _pracownicy[i]->getDzien() << endl;
		cout << _pracownicy[i]->getMiesiac() << endl;
		cout << _pracownicy[i]->getRok() << endl;
		cout << _pracownicy[i]->getPesel() << endl;
		cout << _pracownicy[i]->getMiejscowosc() << endl;
		cout << _pracownicy[i]->getUlica() << endl;
		cout << _pracownicy[i]->getNrDomu() << endl;
		cout << _pracownicy[i]->getNrTel() << endl;
		cout << _pracownicy[i]->getEmail() << endl;
		cout << "Ocena: " << _pracownicy[i]->getOcena() << endl;
		cout << endl << endl;
	}
}

//inicjalizacja pracownika 
void inicjalizuj_gen_pracownika(Pracownik* _pracownicy, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		//_pracownicy[i].pracownik_id = GeneratorLiczba(1, 100);
		_pracownicy[i].setImie(imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)]);
		_pracownicy[i].setNazwisko(nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)]);
		_pracownicy[i].setLogin(GeneratorLogin(_pracownicy[i].getImie(), _pracownicy[i].getNazwisko()));
		_pracownicy[i].setPlec(true);
		_pracownicy[i].setDzien(GeneratorLiczba(1, 30));
		_pracownicy[i].setMiesiac(GeneratorLiczba(1, 12));
		_pracownicy[i].setRok(GeneratorLiczba(1950, 2004));
		_pracownicy[i].setPesel(GeneratorPesel(_pracownicy[i].getDzien(), _pracownicy[i].getMiesiac(), _pracownicy[i].getRok(), _pracownicy[i].getPlec()));
		_pracownicy[i].setMiejscowosc(miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)]);
		_pracownicy[i].setUlica(ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)]);
		_pracownicy[i].setNrDomu(GeneratorLiczba(1, 100));
		_pracownicy[i].setNrTel("+48 123 456 789");
		_pracownicy[i].setEmail(GeneratorEmail(_pracownicy[i].getImie(), _pracownicy[i].getNazwisko()));
	}
}

void inicjalizuj_gen_pracownika(Pracownik** _pracownicy, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		//_pracownicy[i].pracownik_id = GeneratorLiczba(1, 100);
		_pracownicy[i]->setImie(imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)]);
		_pracownicy[i]->setNazwisko(nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)]);
		_pracownicy[i]->setLogin(GeneratorLogin(_pracownicy[i]->getImie(), _pracownicy[i]->getNazwisko()));
		_pracownicy[i]->setPlec(true);
		_pracownicy[i]->setDzien(GeneratorLiczba(1, 30));
		_pracownicy[i]->setMiesiac(GeneratorLiczba(1, 12));
		_pracownicy[i]->setRok(GeneratorLiczba(1950, 2004));
		_pracownicy[i]->setPesel(GeneratorPesel(_pracownicy[i]->getDzien(), _pracownicy[i]->getMiesiac(), _pracownicy[i]->getRok(), _pracownicy[i]->getPlec()));
		_pracownicy[i]->setMiejscowosc(miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)]);
		_pracownicy[i]->setUlica(ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)]);
		_pracownicy[i]->setNrDomu(GeneratorLiczba(1, 100));
		_pracownicy[i]->setNrTel("+48 123 456 789");
		_pracownicy[i]->setEmail(GeneratorEmail(_pracownicy[i]->getImie(), _pracownicy[i]->getNazwisko()));
	}
}

void ocen_pracownika(Pracownik** _pracownicy, const size_t rozmiar) {
	int index = 0;
	unsigned short ocena = 0;
	system("cls");
	cout << "Podaj indeks pracownika: "; cin >> index;
	if (index < rozmiar) {
		cout << "Podaj ocenê w skali od 1 do 10: "; cin >> ocena;
		_pracownicy[index]->setOcena(ocena);
	}
	else {
		cout << "ERROR: Index jest nieprawid³owy !" << endl;
		cin.ignore();
		while (getchar() != '\n');
	}
}

/* poni¿sze funkcje dzia³aj¹ dla STRUKTUR

//inicjalizacja pracownika (ostatni pusty indeks)
void inicjalizuj_pracownika(Pracownik** _pracownicy, const size_t rozmiar, string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel) {
	int i = rozmiar - 1;
	_pracownicy[i]->pracownik_id = GeneratorLiczba(1, 100);
	_pracownicy[i]->imie = imie;
	_pracownicy[i]->nazwisko = nazwisko;
	_pracownicy[i]->login = GeneratorLogin(_pracownicy[i]->imie, _pracownicy[i]->nazwisko);
	_pracownicy[i]->plec = plec;
	_pracownicy[i]->dzien_ur = dzien_ur;
	_pracownicy[i]->miesiac_ur = miesiac_ur;
	_pracownicy[i]->rok_ur = rok_ur;
	_pracownicy[i]->pesel = GeneratorPesel(_pracownicy[i]->dzien_ur, _pracownicy[i]->miesiac_ur, _pracownicy[i]->rok_ur, _pracownicy[i]->plec);
	_pracownicy[i]->miejscowosc = miejscowosc;
	_pracownicy[i]->ulica = ulica;
	_pracownicy[i]->nr_domu = nr_domu;
	_pracownicy[i]->nr_tel = nr_tel;
	_pracownicy[i]->email = GeneratorEmail(_pracownicy[i]->imie, _pracownicy[i]->nazwisko);
}

//inicjalizacja pracownika
void inicjalizuj_gen_pracownika(Pracownik* _pracownicy, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		_pracownicy[i].pracownik_id = GeneratorLiczba(1, 100);
		_pracownicy[i].imie = imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)];
		_pracownicy[i].nazwisko = nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)];
		_pracownicy[i].login = GeneratorLogin(_pracownicy[i].imie, _pracownicy[i].nazwisko);
		_pracownicy[i].plec = true;
		_pracownicy[i].dzien_ur = GeneratorLiczba(1, 30);
		_pracownicy[i].miesiac_ur = GeneratorLiczba(1, 12);
		_pracownicy[i].rok_ur = GeneratorLiczba(1950, 2004);
		_pracownicy[i].pesel = GeneratorPesel(_pracownicy[i].dzien_ur, _pracownicy[i].miesiac_ur, _pracownicy[i].rok_ur, _pracownicy[i].plec);
		_pracownicy[i].miejscowosc = miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)];
		_pracownicy[i].ulica = ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)];
		_pracownicy[i].nr_domu = GeneratorLiczba(1, 100);
		_pracownicy[i].nr_tel = "+48 123 456 789";
		_pracownicy[i].email = GeneratorEmail(_pracownicy[i].imie, _pracownicy[i].nazwisko);
	}
}

void inicjalizuj_gen_pracownika(Pracownik** _pracownicy, const size_t rozmiar) {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < rozmiar; i++) {
		_pracownicy[i]->pracownik_id = GeneratorLiczba(1, 100);
		_pracownicy[i]->imie = imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)];
		_pracownicy[i]->nazwisko = nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)];
		_pracownicy[i]->login = GeneratorLogin(_pracownicy[i]->imie, _pracownicy[i]->nazwisko);
		_pracownicy[i]->plec = true;
		_pracownicy[i]->dzien_ur = GeneratorLiczba(1, 30);
		_pracownicy[i]->miesiac_ur = GeneratorLiczba(1, 12);
		_pracownicy[i]->rok_ur = GeneratorLiczba(1950, 2004);
		_pracownicy[i]->pesel = GeneratorPesel(_pracownicy[i]->dzien_ur, _pracownicy[i]->miesiac_ur, _pracownicy[i]->rok_ur, _pracownicy[i]->plec);
		_pracownicy[i]->miejscowosc = miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)];
		_pracownicy[i]->ulica = ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)];
		_pracownicy[i]->nr_domu = GeneratorLiczba(1, 100);
		_pracownicy[i]->nr_tel = "+48 123 456 789";
		_pracownicy[i]->email = GeneratorEmail(_pracownicy[i]->imie, _pracownicy[i]->nazwisko);
	}
}

void wyswietl_pracownika(Pracownik** _pracownicy, const size_t rozmiar) {
	cout << "--- Pracownicy ---" << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << _pracownicy[i]->pracownik_id << endl;
		cout << _pracownicy[i]->imie << endl;
		cout << _pracownicy[i]->nazwisko << endl;
		cout << _pracownicy[i]->login << endl;
		cout << _pracownicy[i]->plec << endl;
		cout << _pracownicy[i]->dzien_ur << endl;
		cout << _pracownicy[i]->miesiac_ur << endl;
		cout << _pracownicy[i]->rok_ur << endl;
		cout << _pracownicy[i]->pesel << endl;
		cout << _pracownicy[i]->miejscowosc << endl;
		cout << _pracownicy[i]->ulica << endl;
		cout << _pracownicy[i]->nr_domu << endl;
		cout << _pracownicy[i]->nr_tel << endl;
		cout << _pracownicy[i]->email << endl;
		cout << endl << endl;
	}
}
*/