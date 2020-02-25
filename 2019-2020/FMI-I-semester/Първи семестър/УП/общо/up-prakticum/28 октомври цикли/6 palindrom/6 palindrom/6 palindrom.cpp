// 6 palindrom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main() {

	int n, copyN, reverseN;

	cout << "n:";
	cin >> n;

	///Solution idea: reverse the number and check if it equals its initial value

	copyN = n;
	reverseN = 0;

	while (n != 0) {
		reverseN = 10 * reverseN + n % 10;
		n /= 10;
	}

	if (copyN == reverseN)
		cout << "palindrome" << endl;
	else
		cout << "not a palindrome" << endl;

	return 0;
}