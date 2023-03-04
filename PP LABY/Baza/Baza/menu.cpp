#include <iostream>
#include "headers.hpp"

using namespace std;

void menu() {
	//	alokacja pamieci na liste, liste wynikow wyszukiwan
	rower* lista_rowerow = new rower;
	rower* wyniki = new rower;
	string* str = new string;
	wyniki = NULL;
	lista_rowerow = NULL;
	int dec = 0, p;
	//	menu
	do {
		cout << "--------------------------------------------------------------\n\tMENU\n";
		cout << "1 dodanie rejestru\n2 wyszukiwarka (edytuj (wypozycz)/usun)\n";
		cout << "3 wyszukaj za pomoca wyrazen regularnych\n4 wyswietl wszystkie\n5 zapisz\n6 wczytaj\n0 wyjscie\n";
		cin >> dec;
		switch (dec) {
		case 1:
			//	aktualzacja listy o nowy element
			lista_rowerow = dodaj_element(lista_rowerow);
			break;
		case 2:
			//	lista wynikow z elementami wyszukanymi
			wyniki = wyszukiwarka(lista_rowerow);
			//	ewentualna modyfikacja listy
			cout << "Chcesz modyfikowac rejestry? (1 - tak, 0 - nie) ";
			cin >> p;
			if (p) lista_rowerow = modyfikuj_liste(lista_rowerow, wyniki);
			break;
		case 3:
			//	lista wynikow z elementami wyszukanymi
			wyniki = wyszukiwarka_regex(lista_rowerow);
			//	ewentualna modyfikacja listy
			cout << "Chcesz modyfikowac rejestry? (1 - tak, 0 - nie) ";
			cin >> p;
			if (p) lista_rowerow = modyfikuj_liste(lista_rowerow, wyniki);
			break;
		case 4:
			//	decyzja dokladnosci wyswietlenia
			cout << "1 wyswietl standardowo\n2 wyswietl szczegolowo\n";
			cin >> p;
			cout << "Wszystkie rejestry:\n";
			//	komunikat o braku elementow
			if (!lista_rowerow) cout << "baza pusta\n";
			wyniki = lista_rowerow;
			//	wyswietlenie
			while (wyniki) {
				if (p == 2) wyswietl_szczegolowo(wyniki);
				else wyswietl(wyniki);
				wyniki = wyniki->nastepny;
			}
			break;
		case 5:
			//	zapisanie do wskazanego pliku
			cout << "Podaj nazwe (sciezke) pliku: ";
			cin >> *str;
			zapisz_do_pliku(lista_rowerow, *str);
			break;
		case 6:
			//	odczyt ze wskazanego pliku
			cout << "Podaj nazwe (sciezke) pliku: ";
			cin >> *str;
			lista_rowerow = wczytaj_z_pliku(*str);
			break;
		case 0:
			dec = 0;
			break;
		default:
			cout << "\nOpcja niedostepna. Wybierz jedna z listy.\n";
			break;
		}
		//	wyczyszczenie inputu
		cin.clear();
		cin.ignore();
		//	oczekiwanie na kontynuacje
		cout << "\nNacisnij enter, aby kontynuowac...";
		cin.get();
		//	czyszczenie ekranu
		system("CLS");
	} while (dec);
	//	zwolnienie pamieci
	delete str;
	delete wyniki;
	delete lista_rowerow;
}