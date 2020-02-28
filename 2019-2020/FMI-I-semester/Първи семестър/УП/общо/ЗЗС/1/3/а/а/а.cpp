// à.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int p;
	cout << "p=";
	cin >> p;
	bool trueFalse = p % 4 == 0 || p % 7 == 0;
	cout << trueFalse << endl;
	cout << "1:The number is divided by 4 or 7" << endl;
	cout << "0:The number is NOT divided by 4 or 7" << endl;

    return 0;
}

