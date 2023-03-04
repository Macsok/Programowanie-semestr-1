#include <iostream>
#include <cmath>

using namespace std;

//	Rodzina funkcji, przeci¹¿enie (u¿ycie tej samej nazwy dla kilku funkcji, ró¿ne parametry)

unsigned int pot(unsigned int n, unsigned int m) {
	cout << "unsigned int ";
	return pow(n, m);
}

int pot(int n, unsigned int m) {
	cout << "int ";
	return pow(n, m);
}

double pot(double n, unsigned int m) {
	cout << "double ";
	return pow(n, m);
}

int main() {
	cout << pot(+2, +3);
	return 0;
}