#pragma once

#include "towar.h"

void zakup_nowy_towar(Towar*& _towary, size_t& zapisane);
void zakup_nowy_towar(Towar**& _towary, size_t& rozmiar);

void utylizuj_towar(Towar*& _towary, size_t& zapisane); //tego uzywam
void utylizuj_towar(Towar**& _towary, size_t& rozmiar);