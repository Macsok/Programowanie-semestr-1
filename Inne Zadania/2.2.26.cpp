#include <iostream>
using namespace std;

int funkcja(int n) {
    switch (n) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;

        default:
            if( !(n%3) ) return funkcja(n-1) + funkcja(n-2);
            else if ( (n%3) == 1 ) return 5 * funkcja(n-1) + 4;
            else return funkcja(n-1);
    }
}

int main() {
    while(1) {
    int n = -1;
    while (n < 0) {
        cout << "Podaj liczbe: ";
        cin >> n;
    }
    cout << funkcja(n) << endl;
    return 0;
    }   // Do testów
}