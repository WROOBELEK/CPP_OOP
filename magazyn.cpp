////////////////////
// magazyn . cpp
////////////////////

#include <iostream>
#include "magazyn.h"
#include "template.h"


using namespace std;

Magazyn::Magazyn(string login, size_t iloscZatrudnionych) {
	this->login = login;
	this->iloscZatrudnionych = iloscZatrudnionych;
	this->stworz_pracownika();
	this->inicjalizuj_gen_pracownika();
}

Magazyn::~Magazyn() {
	usun(pracownicy, iloscZatrudnionych);
	delete[] this->pracownicy;
}

Magazyn::Magazyn(const Magazyn& obj) {
	login = obj.login;
	iloscZatrudnionych = obj.iloscZatrudnionych;
	pracownicy = new Pracownik * [iloscZatrudnionych];

	for (size_t i = 0; i < iloscZatrudnionych; i++) {
		pracownicy[i] = new Pracownik(*obj.pracownicy[i]);
	}
}
////////////////////////////////////////////////////////////////////
void Magazyn::print() {
	cout << "Login: " << this->login << "\n";
	cout << "Ile zatrudnionych: " << this->iloscZatrudnionych << "\n\n";
}

void Magazyn::stworz_pracownika() {
	this->pracownicy = new Pracownik * [iloscZatrudnionych];
	for (size_t i = 0; i < iloscZatrudnionych; i++) {
		this->pracownicy[i] = new Pracownik();
	}
}

void Magazyn::usun_pracownika(int index) {
	if (index < this->iloscZatrudnionych) {
		Pracownik** temp = new Pracownik * [this->iloscZatrudnionych - 1];
		short int j = -1;
		for (size_t i = 0; i < this->iloscZatrudnionych; ++i) {
			if (i != index) {
				++j;
				temp[j] = pracownicy[i];
			}
		}
		delete[] this->pracownicy;
		this->pracownicy = temp;
		this->iloscZatrudnionych--;
	}
	else
		cout << "ERROR: Index jest nieprawid³owy ! \n";
}

void Magazyn::usun_pracownikow() {
	for (size_t ind = 0; ind < this->iloscZatrudnionych; ind++) {
		delete this->pracownicy[ind];
	}
	delete[] this->pracownicy;
	pracownicy = nullptr;
	this->iloscZatrudnionych = 0;
}

void Magazyn::wyswietl_pracownika() {
	cout << "--- Pracownicy ---" << endl;
	for (int i = 0; i < iloscZatrudnionych; i++) {
		cout << this->pracownicy[i]->getPracownik_ID() << endl;
		cout << this->pracownicy[i]->getImie() << endl;
		cout << this->pracownicy[i]->getNazwisko() << endl;
		cout << this->pracownicy[i]->getLogin() << endl;
		cout << this->pracownicy[i]->getPlec() << endl;
		cout << this->pracownicy[i]->getDzien() << endl;
		cout << this->pracownicy[i]->getMiesiac() << endl;
		cout << this->pracownicy[i]->getRok() << endl;
		cout << this->pracownicy[i]->getPesel() << endl;
		cout << this->pracownicy[i]->getMiejscowosc() << endl;
		cout << this->pracownicy[i]->getUlica() << endl;
		cout << this->pracownicy[i]->getNrDomu() << endl;
		cout << this->pracownicy[i]->getNrTel() << endl;
		cout << this->pracownicy[i]->getEmail() << endl;
		cout << "Ocena: " << this->pracownicy[i]->getOcena() << endl;
		cout << endl << endl;
	}
}

void Magazyn::dodaj_pracownika() {
	Pracownik** temp = new Pracownik * [iloscZatrudnionych + 1];
	if (this->iloscZatrudnionych == 0) {
		temp[iloscZatrudnionych] = new Pracownik;
	}
	else {
		for (size_t i = 0; i < iloscZatrudnionych; i++)
			temp[i] = pracownicy[i];
		temp[iloscZatrudnionych] = new Pracownik;
		delete[] pracownicy;
	}
	pracownicy = temp;
	iloscZatrudnionych++;
}

void Magazyn::inicjalizuj_pracownika(string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel) {
	size_t i = iloscZatrudnionych - 1;
	//this->pracownicy[i]->pracownik_id = GeneratorLiczba(1, 100);
	this->pracownicy[i]->setImie(imie);
	this->pracownicy[i]->setNazwisko(nazwisko);
	this->pracownicy[i]->setLogin(GeneratorLogin(this->pracownicy[i]->getImie(), this->pracownicy[i]->getNazwisko()));
	this->pracownicy[i]->setPlec(plec);
	this->pracownicy[i]->setDzien(dzien_ur);
	this->pracownicy[i]->setMiesiac(miesiac_ur);
	this->pracownicy[i]->setRok(rok_ur);
	this->pracownicy[i]->setPesel(GeneratorPesel(this->pracownicy[i]->getDzien(), this->pracownicy[i]->getMiesiac(), this->pracownicy[i]->getRok(), this->pracownicy[i]->getPlec()));
	this->pracownicy[i]->setMiejscowosc(miejscowosc);
	this->pracownicy[i]->setUlica(ulica);
	this->pracownicy[i]->setNrDomu(nr_domu);
	this->pracownicy[i]->setNrTel(nr_tel);
	this->pracownicy[i]->setEmail(GeneratorEmail(this->pracownicy[i]->getImie(), this->pracownicy[i]->getNazwisko()));
}

void Magazyn::inicjalizuj_gen_pracownika() {
	string imiona[] = { "Piotr", "Pawe³", "Adam", "Kacper", "Maciej", "Janusz", "Rafa³", "Joachim", "Grzegorz", "£ukasz", "Jakub", "Miko³aj", "Julian", "Adrian" };
	string nazwiska[] = { "Nowak", "Kowalski", "Wiœniewski", "Wójcik", "Kowalczyk", "Kamiñski", "Lewandowski", "Zieliñski", "Szymañski", "WoŸniak" };
	string miejscowosci[] = { "Szczecin", "Stargard", "Goleniów", "Gryfino", "Nowogard" };
	string ulice[] = { "¯o³nierska", "Mazowiecka", "Kablowa", "D³uga", "S³oneczna", "Jasna", "Kwiatowa", "Jagielloñska", "Jana Paw³a II" };

	for (int i = 0; i < iloscZatrudnionych; i++) {
		//this->pracownicy[i].pracownik_id = GeneratorLiczba(1, 100);
		this->pracownicy[i]->setImie(imiona[GeneratorLiczba(0, (sizeof(imiona) / sizeof(*imiona)) - 1)]);
		this->pracownicy[i]->setNazwisko(nazwiska[GeneratorLiczba(0, (sizeof(nazwiska) / sizeof(*nazwiska)) - 1)]);
		this->pracownicy[i]->setLogin(GeneratorLogin(this->pracownicy[i]->getImie(), this->pracownicy[i]->getNazwisko()));
		this->pracownicy[i]->setPlec(true);
		this->pracownicy[i]->setDzien(GeneratorLiczba(1, 30));
		this->pracownicy[i]->setMiesiac(GeneratorLiczba(1, 12));
		this->pracownicy[i]->setRok(GeneratorLiczba(1950, 2004));
		this->pracownicy[i]->setPesel(GeneratorPesel(this->pracownicy[i]->getDzien(), this->pracownicy[i]->getMiesiac(), this->pracownicy[i]->getRok(), this->pracownicy[i]->getPlec()));
		this->pracownicy[i]->setMiejscowosc(miejscowosci[GeneratorLiczba(0, (sizeof(miejscowosci) / sizeof(*miejscowosci)) - 1)]);
		this->pracownicy[i]->setUlica(ulice[GeneratorLiczba(0, (sizeof(ulice) / sizeof(*ulice)) - 1)]);
		this->pracownicy[i]->setNrDomu(GeneratorLiczba(1, 100));
		this->pracownicy[i]->setNrTel("+48 123 456 789");
		this->pracownicy[i]->setEmail(GeneratorEmail(this->pracownicy[i]->getImie(), this->pracownicy[i]->getNazwisko()));
	}
}

void Magazyn::ocen_pracownika() {
	int index = 0;
	unsigned short ocena = 0;
	system("cls");
	cout << "Podaj indeks pracownika: "; cin >> index;
	if (index < iloscZatrudnionych) {
		cout << "Podaj ocenê w skali od 1 do 10: "; cin >> ocena;
		this->pracownicy[index]->setOcena(ocena);
	}
	else {
		cout << "ERROR: Index jest nieprawid³owy !" << endl;
		cin.ignore();
		while (getchar() != '\n');
	}
}

Magazyn& Magazyn::operator=(const Magazyn& obj_old) {
	if (&obj_old != this) { //przenosimy do this 
		this->usun_pracownikow();

		login = obj_old.login;
		iloscZatrudnionych = obj_old.iloscZatrudnionych;
		pracownicy = new Pracownik * [iloscZatrudnionych];

		for (size_t i = 0; i < iloscZatrudnionych; i++) {
			pracownicy[i] = new Pracownik(*obj_old.pracownicy[i]);
		}
	}
	return *this;
}

Magazyn::Pracownik* Magazyn::operator[](const size_t i) {
	return pracownicy[i];
}