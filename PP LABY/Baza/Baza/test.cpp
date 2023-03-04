#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream wczytaj("dane.txt");
    char nazwa[256];
    wczytaj.getline(nazwa, 256, '|');

    cout << nazwa;

    wczytaj.close();
    return 0;
}