#include <iostream>
#include <cmath>
using namespace std;

bool trk(float a, float b, float c);
int rodzaj(float a, float b, float c);
void display(bool czy_mozna, int rodzaj);

int main() {
	float t[3];
		for (int i = 0; i < 3; i++) {
			cout << "dl. boku: ";
			cin >> t[i];
			if (t[i] <= 0) {
				cout << "Nieprawidlowa dlugosc boku. Popraw wartosc\n";
				i--;
			}
		}
		display(trk(t[0], t[1], t[2]), rodzaj(t[0], t[1], t[2]));
	return 0;
}

//		0 - nie mozna zbudowac trojkata		1 - mozna
bool trk(float a, float b, float c) {
	if (max(a, max(b, c)) < min(a, min(b, c)) + a + b + c - min(a, min(b, c)) - max(a, max(b, c))) return true;
	else return false;
	//	max, min z dwóch zmiennych!
}

int rodzaj(float a, float b, float c) {
	//		0 - zwykly		1 - rownoboczny		2 - rownoramienny		3 - protokatny		4 - rownoram. prostok.
	if (a == b && a == c) return 1;
	else if (a == b || a == c || b == c)
		if (pow(max(a, max(b, c)), 2) == pow(min(a, min(b, c)), 2) + pow(a + b + c - min(a, min(b, c)) - max(a, max(b, c)), 2)) return 4;
		else return 2;
	else if (pow(max(a, max(b, c)), 2) == pow(min(a, min(b, c)), 2) + pow(a + b + c - min(a, min(b, c)) - max(a, max(b, c)), 2)) return 3;
	else return 0;
}

void display(bool czy_mozna, int rodzaj) {
	if (czy_mozna) {
		cout << "Mozna zbudowac trojkat ";
		switch (rodzaj) {
		case 1:
			cout << "rownoboczny.";
			break;
		case 2:
			cout << "rownoramienny.";
			break;
		case 3:
			cout << "prostokatny.";
			break;
		case 4:
			cout << "rownoramienny, prostokatny.";
			break;
		default:
			break;
		}
	}
	else cout << "Nie mozna zbudowac trojkata.";
}