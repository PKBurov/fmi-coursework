#include <iostream>
using namespace std;

const unsigned short MAX_SIZE = 101;

void Crypto(char str[], int len, int L, int M);
int Strlen(const char* s);
unsigned short SafelyInputNumber(unsigned short lowerBound, unsigned short upperBound);

int main() {

	int L = 0, M = 0, lenght = 0;
	//User input
	char str[MAX_SIZE] = "I am a string";	
	lenght = Strlen(str);
	cout << "Input M: ";
	M = SafelyInputNumber(1, 20);

	cout << "Input L: ";
	L = SafelyInputNumber(1, lenght);
	Crypto(str, lenght, L, M);

	cout << "Output:" << endl;
	for (int i = 0; i < lenght; i++) {

		cout << str[i];
	}
	cout << endl;
	return 0;
}
int Strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}
unsigned short SafelyInputNumber(unsigned short lowerBound, unsigned short upperBound) {

	unsigned short SafeNumber = 0;
	while (true) {
		cin >> SafeNumber;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << "Need valid input: " << endl;
			continue;
		}if ((SafeNumber >= lowerBound) && (SafeNumber < upperBound))
			break;
		else {
			cout << "\n" << "Input in bounds needed: " << endl;
		}
	}
	return SafeNumber;
}
void Crypto(char str[], int length, int L, int M) {

	for (int k = 0; k < length; k++) {
		if (str[k] < 32 || str[k] >= 127) {		//127-th ASCII sybmol is DEL; 32-nd ASCII symbol is SPACE;
			return;
		}
	}
	char strCopy[MAX_SIZE];
	for (int p = 0; p < length; p++) {
		if ((p + L) > (length - 1)) {
			strCopy[(L - (length - p))] = (str[p] + M);
		}else {
			strCopy[p + L] = (str[p] + M);
		}
	}
	strCopy[length] = '\0';
	for (int f = 0; f < length + 1; f++) {
		str[f] = strCopy[f];
	}
}