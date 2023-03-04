#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n = -1, m = 2;
    string s;
    while (n < 0) {
        cout << "Podaj pierwsza liczbe: ";
        getline(cin, s);//      <- "Bezpieczniejsze" zapisanie wejœcia
        n = stoi(s);
    }

    do {
        //cin.clear     <- Czyœci wejœcie
        cout << "Podaj potege: ";
        getline(cin, s);
        if (!s.empty()) m = stoi(s);
    } while ( m < 0);
    
    cout << n << "^" << m << " = " << pow(n, m);
    return 0;
}