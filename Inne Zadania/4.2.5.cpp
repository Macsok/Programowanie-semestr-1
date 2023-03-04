#include <iostream>
#include <cmath>
using namespace std;

bool pierwsza(unsigned int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	unsigned int a;
	cin >> a;
	cout << pierwsza(a);
	return 0;
}