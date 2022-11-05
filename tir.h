#pragma once

#include <string>
#include "generatory.h"
#include "towar.h"

using namespace std;



class Tir {
private:
	size_t* idTir;
	string opis;
public:
	Tir();
	virtual ~Tir();
	virtual void obslugaTira(Towar* towary, size_t& zapisane) = 0;
};

class Dostawa : public Tir {
public:
	~Dostawa();
	void obslugaTira(Towar* towary, size_t& zapisane);
};

class Wysylka : public Tir {
public:
	~Wysylka();
	void obslugaTira(Towar* towary, size_t& zapisane);
};