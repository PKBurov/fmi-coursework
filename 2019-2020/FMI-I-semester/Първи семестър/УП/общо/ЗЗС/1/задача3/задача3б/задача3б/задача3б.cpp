// задача3б.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int a, b, c;
	double D, sqrtD, x1, x2;
	
	cout << "Vuvedete a, b, c za namirane na korenite na kvadratno yrabnenie:" << endl;
	cout << "a=";
	cin >> a;

	cout << "b=" ;
	cin >> b;

	cout << "c=";
	cin >> c;

	D = pow(b, 2) - 4 * a*c;
	cout << "D=" << D << endl;
	sqrtD = sqrt(D);

	
	
	

	if (a != 0 && D >= 0) {
		cout << "Korenite na kv. yravnenie sa:" << endl;
		x1 = (-b + sqrtD) / 2 * a;
		x2 = (-b - sqrtD) / 2 * a;

		cout << "x1=" <<x1<< endl;
		cout << "x2=" << x1 << endl;
	
	}
	else
	{
		cout << "Nqma realni koreni" << endl;
	}

	system("pause");
    return 0;
}

