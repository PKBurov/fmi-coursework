// средно аритметично.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a, b;
	
	cout << "Vuvedete dve chisla A i B" << endl;
	cout << "a=";
	cin >> a; 
	cout << "b=";
	cin >> b;

	double c = (a + b) / 2;
	cout << "Srednoto aritmetichno na chisla e " << c << endl;

    return 0;
}

