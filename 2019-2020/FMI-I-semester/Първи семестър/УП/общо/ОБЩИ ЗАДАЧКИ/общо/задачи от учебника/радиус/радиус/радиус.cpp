// радиус.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double r, C, S;
	double pi;
	cout << "Vuvedete radiusa na okrujnostta: "<<endl;
	cout << "r= ";
	cin >> r;
	pi = 22 / 7;

	C = 2 *pi*r;
	S = pi*r*r;

	cout << "Duljinata na okrujnostta e C= "<< C << endl;
	cout << "S= " << S << endl;

	system("pause");

    return 0;
}

