#pragma once
template<typename A, typename R>
void usun(A obiekt, R rozmiar) {
	for (size_t i = 0; i < rozmiar; i++)
		delete obiekt[i];
}