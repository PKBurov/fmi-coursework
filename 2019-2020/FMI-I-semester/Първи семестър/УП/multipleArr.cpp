#include <iostream>
using namespace std;

const int ARRAY_SIZE = 100;

int* Multiple(int* f, int* s, int n, int m) {

	int size_newArr = ((n > m) ? n : m);
	int* newArr = new int[size_newArr];

	if (n > m) {

		for (int i = 0; i < m; i++) {
			newArr[i] = f[i] * s[i];
		}

		for (int j = m; j < n; j++) {

			newArr[j] = s[j];
		}
	}
	else if (m > n) {

		for (int i = 0; i < n; i++) {
			newArr[i] = f[i] * s[i];
		}

		for (int j = n; j < m; j++) {

			newArr[j] = f[j];
		}
	}
	else {
		for (int i = 0; i < n; i++) {

			newArr[i] = s[i] * f[i];
		}
	}

	return newArr;

	delete[]newArr;
}

int main() {

	int f[ARRAY_SIZE];
	int s[ARRAY_SIZE];

	int n;
	int m;

	cout << "Enter n: " << "\n";
	cin >> n;

	cout << "Enter m: " << "\n";
	cin >> m;

	cout << endl;

	cout << "Enter first array elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}

	cout << "\n";

	cout << "Enter second array elements: " << endl;
	for (int i = 0; i < m; i++) {

		cin >> s[i];
	}

	cout << endl;

	for (int i = 0; i < ((n >= m) ? n : m); i++) {

		cout << *(Multiple(s, f, n, m) + i) << " ";
	}

	//delete[]newArr;
	return 0;
}