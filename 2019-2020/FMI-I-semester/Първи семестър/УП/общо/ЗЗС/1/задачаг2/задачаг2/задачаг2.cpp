// задачаг2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double a, b, rC, rD, R, f;
	cout << "Vuvedete kordinatite na tochka a:" << endl;

	cout << "a=";
	cin >> a;

	cout << "b=";
	cin >> b;

	cout << "A(" << a << ";" << b << ")" << endl;

	if (a*a + b*b <= 25 && a <= 0 && b <= 0)
	{
		cout << "Tochkata prinadleji na 3-ti kvadrant" << endl;
	}
	else
	{
		cout << "Tochkata NE prinadleji na 3-ti kvadrant" << endl;
	}

    return 0;
	system("pause");
}

