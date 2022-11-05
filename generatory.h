#pragma once

#include <string>

using namespace std;

size_t GeneratorLiczba(size_t min, size_t max);
string GeneratorLogin(string name, string surname);
string GeneratorEmail(string name, string surname);
string GeneratorPesel(unsigned short dzien, unsigned short miesiac, unsigned short rok, bool plec);