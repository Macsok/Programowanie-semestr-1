#include <iostream>
using namespace std;
//  Odczyt liczby i wypisanie trojek pitagorejskich (a, b, c takich, że a^2 + b^2 = c^2), składających się z liczb mniejszych od n

void trojki(int do_ilu) {
    int i, j, k;
    for (i = 1; i <= do_ilu; i++) {
        for (j = 1; j < i; j++) {
            for (k = j; k < i; k++) {
                if ( (i*i) == ((j*j) + (k*k)) ) cout << i << "^2 = " << j << "^2 + " << k << "^2\n";
            }
        }
        //cout << endl;
    }
}

int main() {
    int n;
    cout << "podaj liczbe: ";
    cin >> n;
    trojki(n);
    return 0;
}