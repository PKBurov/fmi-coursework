// задача5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int year;
	cout << "Vuvedete godina " << endl;
	cin >> year;

	if (year % 4 == 0)
	{
		cout << "Godinata e visokosna " << endl;
	}
	else
	{
		cout << "Godinata NE e visokosna " << endl;
	}
    return 0;
}

