#include <iostream>
using namespace std;

int silnia( int z) {
    if (z == 0) return 1;
    else return silnia(z - 1) * z;
}

int wyswietl_zlicz(int z) {
    int suma = 0;
    for(int i = 0; i <= z; i++) {
        cout << i << "! + ";
        suma += silnia(i);
    }
    cout << "= " << suma;
    return suma;
}

int main() {
    int n = -1;
    while (n < 0) {
    cout << "Podaj liczbe: ";
    cin >> n;
    }
    wyswietl_zlicz(n);
    return 0;
}