#pragma once

#include <string>
#include "generatory.h"

using namespace std;

class Towar {
private:
	const size_t towar_id;
	string nazwa;
	size_t stan = NULL;
	float cena = NULL;
public:
	Towar() : towar_id{GeneratorLiczba(1,1000)} {}
	void setNazwa(string); string getNazwa();
	void setStan(size_t); size_t getStan();
	void setCena(float); float getCena();
	size_t getTowarID();
};

void stworz_towar(Towar*& _towary);
void stworz_towar(Towar*& _towary, const size_t rozmiar); //tego uzywam
void stworz_towar(Towar**& _towary, const size_t rozmiar);

void usun_towar(Towar*& _towary);
void usun_towar(Towar*& _towary, const size_t rozmiar);
void usun_towar(Towar**& _towary, size_t& rozmiar);

void usun_towar(Towar*& _towary, size_t& zapisane, size_t index); //tego uzywam
void usun_towar(Towar**& _towary, size_t& rozmiar, size_t index);

void dodaj_towar(Towar**& _towary, size_t& rozmiar);

void inicjalizuj_towar(Towar* _towary, size_t& zapisane, string marka, string typ, float cena, size_t stan); //tego uzywam
void inicjalizuj_towar(Towar** _towary, const size_t rozmiar, string marka, string typ, float cena, size_t stan);

void inicjalizuj_gen_towar(Towar* _towary, const size_t rozmiar);
void inicjalizuj_gen_towar(Towar** _towary, const size_t rozmiar);

void wyswietl_towar(Towar* _towary, const size_t zapisane);
void wyswietl_towar(Towar** _towary, const size_t rozmiar);

void oblicz_wartosc_towarow(Towar* _towary, const size_t zapisane);


