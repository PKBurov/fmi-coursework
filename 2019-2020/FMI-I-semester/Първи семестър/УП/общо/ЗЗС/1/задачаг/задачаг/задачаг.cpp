// задачаг.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a, b,rC,rD, R,f;
	cout << "Vuvedete kordinatite na tochka a:" << endl;

	cout << "a=";
	cin >> a;

	cout << "b=";
	cin >> b;

	cout << "A(" << a << ";" << b << ")" << endl;
	cout << "Radiusa e " << endl;
	cin >> f;

	cout << "Vuvedete kordinatite na radiusa R:" << endl;

	cout << "rC=";
	cin >> rC;

	cout << "rD=";
	cin >> rD;

	cout << "R(" << rC << ";" << rD << ")" << endl;

	
	

	if ((a-rC)*(a-rC) + (b - rD)*(b - rD)<f*f)
	{
		cout << "Tochka A prinadleji na vutreshnostta na kruga" << endl;
	}
	else
	{
		cout << "Tochka A NE prinadleji na vutreshnostta na kruga" << endl;
	}

	system("pause");
	return 0;
}

