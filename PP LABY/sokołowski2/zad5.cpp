#include <iostream>
using namespace std;

int main() {
    float a, b;
    char n;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;
    cout << "Wybierz dzialanie (+, - , *, /): ";
    cin >> n;
    switch (n) {
    case '+':
        cout << a << " + " << b << " = " << a + b;
        break;
    case '-':
        cout << a << " - " << b << " = " << a - b;
        break;
    case '*':
        cout << a << " * " << b << " = " << a * b;
        break;
    case '/':
        if (b == 0)
            cout << "Nie mozna dzielic przez zero";
        else
            cout << a << " / " << b << " = " << a / b;
        break;
    default:
        cout << "Bledny znak";
        break;
    }
    return 0;
}