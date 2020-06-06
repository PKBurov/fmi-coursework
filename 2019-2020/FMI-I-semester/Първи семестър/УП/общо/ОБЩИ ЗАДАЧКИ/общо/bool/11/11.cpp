// 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Въведете булева стойност (0 или 1): ";
	int a;
	cin >> a;

	cout << "Въведете друга булева стойност (0 или 1): ";
	int b;
	cin >> b;

	// изчисляване на стойността на a nand b
	bool nand = !(a && b);
	cout << a << " nand " << b << " = " << nand << '\n';
	return 0;
}


