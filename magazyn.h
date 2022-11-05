#pragma once

#include <string>
#include "generatory.h"

using namespace std;

class Magazyn {

	string login;
	size_t iloscZatrudnionych;

	class Pracownik {
		const size_t pracownik_id;
		string imie;
		string nazwisko;
		string login;
		bool plec = NULL;
		unsigned short dzien_ur = NULL;
		unsigned short miesiac_ur = NULL;
		unsigned short rok_ur = NULL;
		string pesel;
		string miejscowosc;
		string ulica;
		unsigned short nr_domu = NULL;
		string nr_tel;
		string email;
		unsigned short ocena = 0;

		friend class Magazyn;

	public:
		Pracownik() : pracownik_id{ GeneratorLiczba(1, 100) } {}
		void setImie(string a) { imie = a; }
		string getImie() { return imie; }

		void setNazwisko(string a) { nazwisko = a; }
		string getNazwisko() { return nazwisko; }

		void setLogin(string a) { login = a; }
		string getLogin() { return login; }

		void setPlec(bool a) { plec = a; }
		bool getPlec() { return plec; }

		void setDzien(unsigned short a) { dzien_ur = a; }
		unsigned short getDzien() { return dzien_ur; }

		void setMiesiac(unsigned short a) { miesiac_ur = a; }
		unsigned short getMiesiac() { return miesiac_ur; }

		void setRok(unsigned short a) { rok_ur = a; }
		unsigned short getRok() { return rok_ur; }

		void setPesel(string a) { pesel = a; }
		string getPesel() { return pesel; }

		void setMiejscowosc(string a) { miejscowosc = a; }
		string getMiejscowosc() { return miejscowosc; }

		void setUlica(string a) { ulica = a; }
		string getUlica() { return ulica; }

		void setNrDomu(unsigned short a) { nr_domu = a; }
		unsigned short getNrDomu() { return nr_domu; }

		void setNrTel(string a) { nr_tel = a; }
		string getNrTel() { return nr_tel; }

		void setEmail(string a) { email = a; }
		string getEmail() { return email; }

		void setOcena(unsigned short a) { ocena = a; }
		unsigned short getOcena() { return ocena; }

		size_t getPracownik_ID() { return pracownik_id; }
	};

	Pracownik** pracownicy;

public:
	Magazyn(string login = "default", size_t iloscZatrudnionych = 5);
	~Magazyn();
	Magazyn(const Magazyn& obj);

	void print();

	///

	///

	void stworz_pracownika();
	void usun_pracownika(int index);
	void usun_pracownikow();
	void dodaj_pracownika();
	void wyswietl_pracownika();
	void inicjalizuj_pracownika(string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel);
	void inicjalizuj_gen_pracownika();
	void ocen_pracownika();

	Magazyn& operator=(const Magazyn&); //przeciazenie operatora =

	Magazyn::Pracownik* operator [](const size_t); //przeciazenie operatora []

	friend ostream& operator<<(ostream& out, const Magazyn& magazyn) { //operatora <<
		for (int i = 0; i < magazyn.iloscZatrudnionych; i++)
			out << magazyn.pracownicy[i]->getImie() << "\n";
		return out;
	}
};