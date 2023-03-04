#include <iostream>
#include <cmath>
using namespace std;

bool trk(float a, float b, float c) {
	if (max(a, max(b, c)) < min(a, min(b, c)) + a + b + c - min(a, min(b, c)) - max(a, max(b, c))) return true;
	else return false;
	//	max, min z dwóch zmiennych!
}

int main() {
	float t[3];
	while (true) {
		for (int i = 0; i < 3; i++) {
			cout << "dl. boku: ";
			cin >> t[i];
		}
		cout << trk(t[0], t[1], t[2]) << endl;
	}
	return 0;
}