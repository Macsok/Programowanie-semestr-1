#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "Podaj pierwsza liczbe: ";
	cin >> a;
	cout << "Podaj druga liczbe: ";
	cin >> b;
	cout << "Podaj trzecia liczbe: ";
	cin >> c;
	float d = a + b + c;
	cout << d/3;
	return 0;
}