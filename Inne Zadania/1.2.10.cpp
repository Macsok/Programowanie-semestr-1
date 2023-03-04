#include <iostream>
using namespace std;
//  Odczyt liczby i wartosc bezwzgledna
int main() {
    int l;
    cout << "Podaj liczbe: ";
    cin >> l;
    if (l < 0) l=-l;
    cout << "Modul twojej liczby to: " << l;
    return 0;
}