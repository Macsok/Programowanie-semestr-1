#include <iostream>
using namespace std;

double zad1(double *a, double *b);
void zad2(int *a, int *b);
void zad3(int &x, int &y);
void zad4();
void zad5();
void zad6();

int main() {
    //  zad 1
    double a = 2.4, b = 0.5;
    cout << zad1(&a, &b) << endl;

    //  zad 2
    int x = 3, y = 4;
    zad2(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    //  zad 3
    zad3(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    zad4();
    zad5();
    zad6();
    return 0;
}

double zad1(double *a, double *b) {
    if(*a < *b) return *a;
    else return *b;
}

void zad2(int *a, int *b) {
    if(*b > *a) {
        int buff = *b;
        *b = *a;
        *a = buff;
    }
}

void zad3(int &x, int &y) {
    int buff = x;
    x = y;
    y = buff;
}

void zad4() {
    char _char[] = "programming";
    char *wsk = _char;
    int i = 0;
    //  Petla po calym lancuchu _char[]
    while(_char[i] != '\0') {
        if(i == 0) std::cout << _char[0] << ", " << &wsk << ", " << i << std::endl;
        if(*wsk == 'o') std::cout << *wsk << ", ";
        if(*wsk == 'n') std::cout << *wsk;
        wsk++;
        i++;
    }
    cout << endl;
}

void zad5() {
    int tab[6] = {0, 1, 2, 3, 4, 5};
    int *wsk = &tab[5];
    //  Odczyt tablicy od konca (n = 6)
    for(int i = 0; i < 6; i++) {
        std::cout << *wsk << "\t";
        wsk--;
    }
    cout << endl;
}

void zad6() {
    char chain_1[] = "loko";
    char chain_2[] = "motywa";
    char output[50] = {};
    char *ptr_1 = chain_1, *ptr_2 = chain_2;
    int i = 0;
    //  Przypisywanie kolejno pierwszej i drugiej czesci do calosci
    while (*ptr_1) {
        output[i] = *ptr_1;
        ptr_1++;
        i++;
    }
    while (*ptr_2) {
        output[i] = *ptr_2;
        ptr_2++;
        i++;
    }
    cout << output;
}