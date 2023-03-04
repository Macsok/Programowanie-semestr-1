#include <iostream>

int absolute(int n) {
	if (n < 0) return -n;
	else return n;
}

int main() {
	int n;
	std::cout << "Podaj liczbe: ";
	std::cin >> n;
	std::cout << absolute(n);
	return 0;
}