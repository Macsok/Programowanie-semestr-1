#include <iostream>
#include <cmath>
using namespace std;

int zaokr_pierw(int l, float stopien) {
    return floor(pow(l, (1/stopien)));
}

int zlicz_wypisz(int do_n, int st) {
    int suma = 0;
    for(int i = 0; i <= do_n; i++) {
        cout << "(" << st << ")" << i << " + ";
        suma += zaokr_pierw(i, st);
    }
    cout << "= " << suma;
    return suma;
}

int main() {
    int n = -1, m = -1;
    while (n < 0) {
        cout << "Podaj zakres liczb: ";
        cin >> n;
    }

    while (m < 2) {
        cout << "Podaj stopien pierwiastka (>1): ";
        cin >> m;
    }
    zlicz_wypisz(n, m);
    return 0;
}