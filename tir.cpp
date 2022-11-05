////////////////////
// tir . cpp
////////////////////

#include <iostream>
#include <string>
#include "tir.h"
#include "towar.h"

using namespace std;

Tir::Tir() {
	this->idTir = new size_t[GeneratorLiczba(1, 1000)];
}

Tir::~Tir() {
	cout << "Destruktor g³ówny" << endl;
	delete this->idTir;
}

void Wysylka::obslugaTira(Towar* towary, size_t& zapisane) {
	for (int i = 0; i < zapisane; i++) {
		int temp = towary[i].getStan() - GeneratorLiczba(5, 300);
		if (temp < 0)
			temp = 0;
		towary[i].setStan(temp);
	}
	cout << "TIR z towarem wyjechal z centrum wysylkowego." << endl;
}

Wysylka::~Wysylka() {
	cout << "Destruktor wysylka" << endl;
}

void Dostawa::obslugaTira(Towar* towary, size_t& zapisane) {
	for (int i = 0; i < zapisane; i++) {
		int temp = towary[i].getStan() + GeneratorLiczba(5, 300);
		towary[i].setStan(temp);
	}
	int old_zapisane = zapisane;
	zapisane = zapisane + GeneratorLiczba(1, 3);
	string marka[] = { "XLMOTO", "Sledstore", "24MX", "Alpinestars", "Fox", "Bell", "Course", "Acerbis", "Proworks", "Nexx" };
	string typ[] = { "Kask", "Kombinezon", "Rêkawice", "Ochraniacze", "Plecak", "Grip", "Buty", "Komplet", "Kurtka", "Spodnie" };

	for (int i = old_zapisane; i < zapisane; i++) {
		int temp = towary[i].getStan() + GeneratorLiczba(5, 300);
		towary[i].setNazwa(marka[GeneratorLiczba(0, (sizeof(marka) / sizeof(*marka)) - 1)] + " " + typ[GeneratorLiczba(0, (sizeof(typ) / sizeof(*typ)) - 1)]);
		towary[i].setStan(GeneratorLiczba(1, 10000));
		towary[i].setCena(GeneratorLiczba(60, 1500));
	}
	cout << "TIR z towarem wlasnie przyjechal." << endl;
}

Dostawa::~Dostawa() {
	cout << "Destruktor dostawa" << endl;
}


