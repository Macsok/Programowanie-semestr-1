#include <iostream>
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//	struktura daty
struct _data {
	int dzien = 0;
	int miesiac = 0;
	int rok = 0;
};

//	Struktura obiektu rower
struct rower {
	char nazwa_producenta[256] = {};
	char kolor[50] = {};
	std::string typ = "";
	float srednica_kola = 0;

	float cena_za_dzien = 0;
	float kaucja = 0;

	_data data_przegladu;
	_data data_wypozyczenia;
	_data zwrot_do;
	rower* nastepny = NULL;
};

//	Funkcje (functions.cpp)
void menu();
rower* dodaj_element(rower* lista);
rower* wyszukiwarka(rower* lista);
std::string menu_wyboru_typu();
void wyswietl(rower* element);
void wyswietl_szczegolowo(rower* element);
rower* odlacz_od_listy(rower* lista, rower* element);
rower* modyfikuj_liste(rower* lista_glowna, rower* lista_wybranych_rejestrow);
void zapisz_do_pliku(rower* lista, std::string nazwa_pliku);
rower* dolacz_do_listy(rower* lista, rower* element);
rower* wczytaj_z_pliku(std::string nazwa_pliku);
rower* wyszukiwarka_regex(rower* lista);

#endif
