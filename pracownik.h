#pragma once

#include <string>
#include "generatory.h"

using namespace std;

class Pracownik {
private:
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
public:
	Pracownik() : pracownik_id{ GeneratorLiczba(1, 100) } {}
	void setImie(string); string getImie();
	void setNazwisko(string); string getNazwisko();
	void setLogin(string); string getLogin();
	void setPlec(bool); bool getPlec();
	void setDzien(unsigned short); unsigned short getDzien();
	void setMiesiac(unsigned short); unsigned short getMiesiac();
	void setRok(unsigned short); unsigned short getRok();
	void setPesel(string); string getPesel();
	void setMiejscowosc(string); string getMiejscowosc();
	void setUlica(string); string getUlica();
	void setNrDomu(unsigned short); unsigned short getNrDomu();
	void setNrTel(string); string getNrTel();
	void setEmail(string); string getEmail();
	void setOcena(unsigned short); unsigned short getOcena();
	size_t getPracownik_ID();
};

/*
struct Pracownik {
	unsigned int pracownik_id;
	string imie;
	string nazwisko;
	string login;
	bool plec;
	unsigned short dzien_ur;
	unsigned short miesiac_ur;
	unsigned short rok_ur;
	string pesel;
	string miejscowosc;
	string ulica;
	unsigned short nr_domu;
	string nr_tel;
	string email;
};
*/

void stworz_pracownika(Pracownik*& _pracownicy);
void stworz_pracownika(Pracownik*& _pracownicy, const size_t rozmiar);
void stworz_pracownika(Pracownik**& _pracownicy, const size_t rozmiar);

void usun_pracownika(Pracownik*& _pracownicy);
void usun_pracownika(Pracownik*& _pracownicy, const size_t rozmiar);
void usun_pracownika(Pracownik**& _pracownicy, size_t& rozmiar);
void usun_pracownika(Pracownik**& _pracownicy, size_t& rozmiar, size_t index);

void dodaj_pracownika(Pracownik**& _pracownicy, size_t& rozmiar);

void inicjalizuj_pracownika(Pracownik** _pracownicy, const size_t rozmiar, string imie, string nazwisko, bool plec, unsigned short dzien_ur, unsigned short miesiac_ur, unsigned short rok_ur, string miejscowosc, string ulica, unsigned short nr_domu, string nr_tel);

void inicjalizuj_gen_pracownika(Pracownik* _pracownicy, const size_t rozmiar);
void inicjalizuj_gen_pracownika(Pracownik** _pracownicy, const size_t rozmiar);

void wyswietl_pracownika(Pracownik** _pracownicy, const size_t rozmiar);

void ocen_pracownika(Pracownik** _pracownicy, const size_t rozmiar);




