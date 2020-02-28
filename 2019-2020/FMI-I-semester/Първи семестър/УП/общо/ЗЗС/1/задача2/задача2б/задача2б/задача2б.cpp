// задача2б.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double a, b,c,p;
	double S;
	cout << "Vuvedete trite strani na triugulnika" << endl;
	cin >> a >> b >> c;

	p = (a + b + c) /2;
	S = sqrt(p*(p - a)*(p - b)*(p - c));

	cout << "Licheto na triugulnika e S=" << S << endl;
	
    return 0;
}

