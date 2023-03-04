#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "headers.hpp"

using namespace std;

//Dodawanie nowego rejestru
rower* dodaj_element(rower* lista) {
	//	alokacja pamieci na nowy element
	rower* nowy = new rower;
	int a;
	//	czyszczenie inputu
	cin.clear();
	cin.ignore();
	//	pobieranie kryteriow
	cout << "Nazwa producenta: ";
	std::cin.getline(nowy->nazwa_producenta, 256);
	cin.clear();
	cout << "Kolor: ";
	cin.getline(nowy->kolor, 50);
	cin.clear();
	nowy->typ = menu_wyboru_typu();
	cin.clear();
	//	sprawdzanie kryteriow wprowadzanych danych
	do {
		cout << "Srednica kola: ";
		cin >> (nowy->srednica_kola);
		if (nowy->srednica_kola <= 0 || nowy->srednica_kola >= 100) cout << "niepoprawne dane (1 - 99)\n";
	} while (nowy->srednica_kola <= 0 || nowy->srednica_kola >= 100);
	cin.clear();
	cin.ignore();
	do {
		cout << "Kaucja: ";
		cin >> nowy->kaucja;
		if(nowy->kaucja <= 0) cout << "niepoprawne dane (x > 0)\n";
	} while (nowy->kaucja <= 0);
	cin.clear();
	cin.ignore();
	do {
		cout << "Cena za dzien: ";
		cin >> nowy->cena_za_dzien;
		if (nowy->cena_za_dzien <= 0) cout << "niepoprawne dane (x > 0)\n";
	} while (nowy->cena_za_dzien <= 0);
	cin.clear();
	cin.ignore();
	cout << "Data ostatniego przegaldu (dd/mm/rrrr):\n";
	//	sprawdzanie podstawowych kryteriow daty
	do {
		cout << "dzien: ";
		cin >> a;
		//	sprawdzanie daty
		if (a > 0 && a < 32) nowy->data_przegladu.dzien = a;
		else cout << "niepoprawna data (1 < dd < 31)\n";
	} while (a <= 0 || a >= 32);
	do {
		cout << "miesiac: ";
		cin >> a;
		if (a > 0 && a < 13) nowy->data_przegladu.miesiac = a;
		else cout << "niepoprawna data (1 < mm < 12)\n";
	} while (a <= 0 || a >= 13);
	do {
		cout << "rok: ";
		cin >> a;
		if (a > 2000 && a < 2030) nowy->data_przegladu.rok = a;
		else cout << "niepoprawna data (2000 << rrrr << 2030)\n";
	} while (a <= 1999 || a > 2030);
	cin.clear();
	cin.ignore();
	cout << "Data wypozyczenia (dd/mm/rrrr):\n";
	//	petla do wymuszenia poprawnych danych
	do {
		cout << "dzien: ";
		cin >> a;
		//	sprawdzanie daty
		if (a > 0 && a < 32) nowy->data_wypozyczenia.dzien = a;
		else cout << "niepoprawna data (1 < dd < 31)\n";
	} while (a <= 0 || a >= 32);
	do {
		cout << "miesiac: ";
		cin >> a;
		if (a > 0 && a < 13) nowy->data_wypozyczenia.miesiac = a;
		else cout << "niepoprawna data (1 < mm < 12)\n";
	} while (a <= 0 || a >= 13);
	do {
		cout << "rok: ";
		cin >> a;
		if (a > 2000 && a < 2030) nowy->data_wypozyczenia.rok = a;
		else cout << "niepoprawna data (2000 << rrrr << 2030)\n";
	} while (a <= 1999 || a > 2030);
	cin.clear();
	cin.ignore();
	cout << "Data zwrotu (dd/mm/rrrr):\n";
	do {
		cout << "dzien: ";
		cin >> a;
		if (a > 0 && a < 32) nowy->zwrot_do.dzien = a;
		else cout << "niepoprawna data (1 < dd < 31)\n";
	} while (a <= 0 || a >= 32);
	do {
		cout << "miesiac: ";
		cin >> a;
		if (a > 0 && a < 13) nowy->zwrot_do.miesiac = a;
		else cout << "niepoprawna data (1 < mm < 12)\n";
	} while (a <= 0 || a >= 13);
	do {
		cout << "rok: ";
		cin >> a;
		if (a > 2000 && a < 2030) nowy->zwrot_do.rok = a;
		else cout << "niepoprawna data (2000 << rrrr << 2030)\n";
	} while (a <= 1999 || a > 2030);
	cin.clear();
	cin.ignore();
	cout << "\nPomyslnie zaaktualizowano\n";
	nowy->nastepny = lista;
	return nowy;
}

//Wyszukuje elementy i zwraca liste wynikow
rower* wyszukiwarka(rower* lista) {
	rower dane;

	//	Pobranie kryteriow
	cin.clear();
	cin.ignore();
	cout << "Podaj kryteria szukanych rejestrow (0 jesli nie dotyczy)\nNazwa producenta: ";
	cin.getline(dane.nazwa_producenta, 256);
	cin.clear();
	cout << "Kolor: ";
	cin.getline(dane.kolor, 50);
	cin.clear();
	dane.typ = menu_wyboru_typu();
	cout << "Srednica kola: ";
	cin >> dane.srednica_kola;
	cin.clear();
	cin.ignore();
	//	Wyswietlenie pasujacych rejestrow, tworzenie listy kopii
	rower* wyniki_wyszukiwania = new rower;
	rower kopia;
	wyniki_wyszukiwania = NULL;
	cout << endl << "Pasujace wyniki:" << endl;
	int i = 0;
	while(lista) {
		//	porownanie danych elementow
		if (string(lista->nazwa_producenta) == string(dane.nazwa_producenta) 
			|| string(lista->kolor) == string(dane.kolor) || lista->typ == dane.typ || lista->srednica_kola == dane.srednica_kola) {
			//	Kopiowanie pasujacego elementu
			kopia = *lista;
			kopia.nastepny = NULL;
			//	Dodawanie kopii elementu do listy wynikow
			wyniki_wyszukiwania = dolacz_do_listy(wyniki_wyszukiwania, &kopia);
			//	Wyswietlenie pasujacego
			cout << "#" << i << " - ";
			wyswietl(&kopia);
			i++;
		}
		lista = lista->nastepny;
	}
	return wyniki_wyszukiwania;
}

//Wybierz typ z pliku, zwraca wybrany typ
string menu_wyboru_typu() {
	ifstream typy("typy.txt");
	//	sprawdzenie poprawnosci otawrcia pliku
	if (!typy.good()) {
		cout << "Blad otwarcia pliku z typami.\n";
		return "nie okreslono";
	}
	int dl = 1, i;
	//	Pobranie dlugosci
	typy >> dl;
	//	Wczytanie typow
	string* s_typy = new string[dl];
	for (i = 0; i < dl; i++)
		getline(typy, s_typy[i]);
	//	Menu typow
	int n = 0;
	cout << "Wybierz jeden z typow (numer):\n";
	for (i = 1; i < dl; i++)
		cout << i << " " << s_typy[i] << endl;
	//	wybor z listy
	i--;
	do {
		cout << "Wybrany numer: ";
		cin >> n;
		cin.clear();
		cin.ignore();
		if (n < 1 || n > i) cout << "wybierz element z listy\n";
	} while (n < 1 || n > i);
	//	Wybor i zwalnianie pamieci
	string str = string(s_typy[n]);
	//	zwolnienie pamieci
	delete[] s_typy;
	//	zamkniecie pliku
	typy.close();
	return str;
}

//Wyswietl dany element
void wyswietl(rower* element) {
	//	wyswietlenie podstawowych danych
	cout << element->nazwa_producenta << " - " << element->kolor << " - " << element->typ << " - " << element->srednica_kola << endl;
}

//Wyswietl wszystkie dane elementu
void wyswietl_szczegolowo(rower* element) {
	//	wyswietlenie wszystkich danych roweru
	cout << "(nazwa) " << element->nazwa_producenta << " - (kolor) " << element->kolor << " - (typ) " << element->typ
		<< " - (sr. kola) " << element->srednica_kola << " - (cena za dzien) " << element->cena_za_dzien
		<< " - (kaucja) " << element->kaucja
		<< " - (data przegl.) " << element->data_przegladu.dzien << "/" << element->data_przegladu.miesiac << "/" << element->data_przegladu.rok
		<< " - (data wypoz.) " << element->data_wypozyczenia.dzien << "/" << element->data_wypozyczenia.miesiac << "/" << element->data_wypozyczenia.rok
		<< " - (dzien zwrotu) " << element->zwrot_do.dzien << "/" << element->zwrot_do.miesiac << "/" << element->zwrot_do.rok << endl;
}

//Odlacz dany element od listy, zwraca wskazniki na poczatek listy
rower* odlacz_od_listy(rower* lista, rower* element) {
	//	stworzenie wskaznikow na glowe i ogon listy (uwzglednienie przypadkow skrajnych)
	rower* glowa = lista;
	rower* ogon = lista;
	rower* poprzedni = lista;
	int ile = 0;
	//	odczytanie dlugosci listy
	while (lista) {
		ile++;
		ogon = lista;
		lista = lista->nastepny;
	}
	lista = glowa;
	//	WLasciwe usuwanie
	for (int i = 0; i < ile; i++) {
		//	Sprawdzanie kryteriow
		if (element == lista) {
			//	Usun pierwsze
			if (lista == glowa) {
				if (glowa == ogon) return NULL;
				else {
					glowa = lista->nastepny;
				}
			}
			//	Usun srodkowe
			else if (lista != ogon) {
				poprzedni->nastepny = lista->nastepny;
			}
			//	Usun ogon
			else {
				poprzedni->nastepny = NULL;
			}
			return glowa;
		}
		//	przypisanie poprzedniego
		poprzedni = lista;
		//	przesuniecie na kolejny element
		lista = lista->nastepny;
	}
	return glowa;
}

//Menu modyfikowania listy wybranych, zwraca wskaznik na nowa liste glowna
rower* modyfikuj_liste(rower* lista_glowna, rower* lista_wybranych_rejestrow) {
	// tworzenie glowy i kopii
	int ile = 0, dec, wybrany;
	rower* glowa = lista_glowna;
	rower* kopia = NULL;
	rower* glowa_kopii = lista_wybranych_rejestrow;
	cout << endl;
	cout << "1 zaznacz wszystkie\n2 wybierz jeden\n0 wyjdz\n";
	cin >> ile;

	//	Wybranie jednego
	if (ile == 2) {
		cout << "Podaj indeks wybranego elementu: ";
		cin >> wybrany;
		//	odczytanie dlugosci listy wybranych el.
		int dlugosc = 0;
		while (lista_wybranych_rejestrow) {
			lista_wybranych_rejestrow = lista_wybranych_rejestrow->nastepny;
			dlugosc++;
		}
		//	aktualizacja dlugosci
		dlugosc--;
		//	cofniecie na poczatek listy
		lista_wybranych_rejestrow = glowa_kopii;
		//	wybranie odpowiedniego indeksu
		for (int i = 0; i < (dlugosc - wybrany); i++) {
			lista_wybranych_rejestrow = lista_wybranych_rejestrow->nastepny;
			if (lista_wybranych_rejestrow == NULL) return lista_glowna;
		}
		//	Wyczyszczenie reszty listy
		lista_wybranych_rejestrow->nastepny = NULL;
	}

	//	Edytuj / usun
	if (ile) {
		cout << "1 usun\n2 edytuj\n";
		cin >> dec;
		//	Usun
		if (dec == 1) {
			//	Usuniecie listy wybranych

			while (lista_wybranych_rejestrow) {
				//	Cofnniecie na poczatek (dla list odwrotnych)
				lista_glowna = glowa;
				while (lista_glowna && lista_wybranych_rejestrow) {
					//	Warunki porownawcze
					if (*lista_glowna->nazwa_producenta == *lista_wybranych_rejestrow->nazwa_producenta &&
						*lista_glowna->kolor == *lista_wybranych_rejestrow->kolor &&
						lista_glowna->typ == lista_wybranych_rejestrow->typ &&
						lista_glowna->srednica_kola == lista_wybranych_rejestrow->srednica_kola) {
						//	Aktualizacja glowy
						if (lista_glowna == glowa) glowa = lista_glowna->nastepny;
						cout << "Usunieto: ";
						wyswietl(lista_glowna);
						//	odlaczenie elementu
						lista_glowna = odlacz_od_listy(glowa, lista_glowna);
						lista_wybranych_rejestrow = lista_wybranych_rejestrow->nastepny;
					}
					//	nastepny element
					if(lista_glowna) lista_glowna = lista_glowna->nastepny;
				}
			}


		}

		//	Modyfikuj
		else {
			while (lista_wybranych_rejestrow) {
				//	Cofnniecie na poczatek (dla list odwrotnych)
				lista_glowna = glowa;
				while (lista_glowna && lista_wybranych_rejestrow) {
					//	warunki porownawcze
					if (*lista_glowna->nazwa_producenta == *lista_wybranych_rejestrow->nazwa_producenta &&
						*lista_glowna->kolor == *lista_wybranych_rejestrow->kolor &&
						lista_glowna->typ == lista_wybranych_rejestrow->typ &&
						lista_glowna->srednica_kola == lista_wybranych_rejestrow->srednica_kola) {
						//	Edycja danych elementu
						//	kopiowanie wskaznika na nastepny element
						glowa_kopii = lista_glowna->nastepny;
						kopia = dodaj_element(kopia);
						//	nadpisanie nowym elementem
						*lista_glowna = *kopia;
						//	przywrocenie reszty listy
						lista_glowna->nastepny = glowa_kopii;
						kopia = NULL;
						//	przejscie na koljeny element
						lista_wybranych_rejestrow = lista_wybranych_rejestrow->nastepny;
					}
					//	nastepny element
					lista_glowna = lista_glowna->nastepny;
				}
			}
		}
	}

	//	powrot na poczatek listy
	lista_glowna = glowa;
	return lista_glowna;
}

//Zapisanie do pliku (.\dane.txt)
void zapisz_do_pliku(rower* lista, string nazwa_pliku) {
	//	otwarcie pliku
	ofstream zapisz(nazwa_pliku + ".txt");
	//	zapisywanie kolejnych elementow listy
	while (lista) {
		zapisz << lista->nazwa_producenta << "|" << lista->kolor << "|" << lista->typ << "|" << lista->srednica_kola << "|"
			<< lista->kaucja << "|" << lista->cena_za_dzien << "|"
			<< lista->data_przegladu.dzien << "|" << lista->data_przegladu.miesiac << "|" << lista->data_przegladu.rok << "|" << lista->data_wypozyczenia.dzien
			<< "|" << lista->data_wypozyczenia.miesiac << "|" << lista->data_wypozyczenia.rok << "|" << lista->zwrot_do.dzien << "|" << lista->zwrot_do.miesiac
			<< "|" << lista->zwrot_do.rok << "\n";
		lista = lista->nastepny;
	}
	cout << "Zapisano.\n";
	//	zamkniecie pliku
	zapisz.close();
}

//Dolaczanie elementu - alokacja nowej pamieci
rower* dolacz_do_listy(rower* lista, rower* element) {
	rower* nowy = new rower;
	//	kopiowanie danych elementu
	*nowy = *element;
	nowy->nastepny = lista;
	return nowy;
}

//Wczytanie listy z pliku
rower* wczytaj_z_pliku(string nazwa_pliku) {
	//	alokacja pamieci
	rower* dane = new rower;
	rower* lista = new rower;
	lista = NULL;
	string str;
	// otwarcie pliku
	ifstream wczytaj(nazwa_pliku + ".txt");

	//	wczytywanie wszystkich rejestrow
	while (wczytaj.good()) {
		//	wczytywanie do znaku specjalnego - |
		wczytaj.getline(dane->nazwa_producenta, 256, '|');
		wczytaj.getline(dane->kolor, 50, '|');
		getline(wczytaj, str, '|');
		//	odrzucenie konca pliku '\n'
		if (str.length() <= 1) break;
		dane->typ = str;
		getline(wczytaj, str, '|');
		dane->srednica_kola = (float)stod(str);
		getline(wczytaj, str, '|');
		dane->kaucja = (float)stod(str);
		getline(wczytaj, str, '|');
		dane->cena_za_dzien = (float)stod(str);
		getline(wczytaj, str, '|');
		dane->data_przegladu.dzien = stoi(str);
		getline(wczytaj, str, '|');
		dane->data_przegladu.miesiac = stoi(str);
		getline(wczytaj, str, '|');
		dane->data_przegladu.rok = stoi(str);
		getline(wczytaj, str, '|');
		dane->data_wypozyczenia.dzien = stoi(str);
		getline(wczytaj, str, '|');
		dane->data_wypozyczenia.miesiac = stoi(str);
		getline(wczytaj, str, '|');
		dane->data_wypozyczenia.rok = stoi(str);
		getline(wczytaj, str, '|');
		dane->zwrot_do.dzien = stoi(str);
		getline(wczytaj, str, '|');
		dane->zwrot_do.miesiac = stoi(str);
		getline(wczytaj, str);
		dane->zwrot_do.rok = stoi(str);
		dane->nastepny = NULL;

		//	tworzenie listy z kolejnych danych
		lista = dolacz_do_listy(lista, dane);
		//wyswietl_szczegolowo(dane);
	}
	// zamkniecie pliku
	wczytaj.close();
	return lista;
}

//Stworz liste wynikow wyszukiwania regex
rower* wyszukiwarka_regex(rower* lista) {
	string str;
	int i = 0;
	//	pobranie wyrazenia regularnego
	cin.ignore();
	cin.clear();
	cout << "Podaj wyrazenie: ";
	getline(cin, str);
	regex wyrazenie(str);

	//	alokacja listy wynikow
	rower* wyniki = new rower;
	wyniki = NULL;

	//	szukaniewynikow
	while (lista) {
		//	stworzenie ciagu znakow do przeszukania
		str = "";
		str += string(lista->nazwa_producenta) + " ";
		str += string(lista->kolor) + " ";
		str += string(lista->typ) + " ";
		str += to_string(lista->kaucja) + " ";
		str += to_string(lista->srednica_kola) + " ";
		str += to_string(lista->cena_za_dzien) + " ";

		str += to_string(lista->data_przegladu.dzien) + " ";
		str += to_string(lista->data_przegladu.miesiac) + " ";
		str += to_string(lista->data_przegladu.rok) + " ";
		str += to_string(lista->data_wypozyczenia.dzien) + " ";
		str += to_string(lista->data_wypozyczenia.miesiac) + " ";
		str += to_string(lista->data_wypozyczenia.rok) + " ";
		str += to_string(lista->zwrot_do.dzien) + " ";
		str += to_string(lista->zwrot_do.miesiac) + " ";
		str += to_string(lista->zwrot_do.rok);

		//	sprawdzenie kryteriow
		if (regex_search(str, wyrazenie)) {
			//	tworzenie listy wynikow
			wyniki = dolacz_do_listy(wyniki, lista);

			//	wyswietlenie wynikow
			cout << "#" << i << " - ";
			wyswietl_szczegolowo(wyniki);
			i++;
		}
		//	przesuniecie na kolejny element
		lista = lista->nastepny;
	}
	return wyniki;
}