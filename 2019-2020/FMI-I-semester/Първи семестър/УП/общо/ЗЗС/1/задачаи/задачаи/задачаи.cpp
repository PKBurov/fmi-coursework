// задачаи.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a,b,c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	if (a < 0 && b < 0 && c < 0)
	{
		cout << "Vsichki chisla sa otrichatelni" << endl;
	}
	else
	{
		cout << "Pone edno ot chislata e otrichatelno" << endl;
	}
	return 0;
}

