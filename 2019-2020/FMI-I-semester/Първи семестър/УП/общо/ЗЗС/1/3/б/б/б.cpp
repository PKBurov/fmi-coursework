// á.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	bool D = b*b - 4 * a*c > 0;
	cout << D << endl;

    return 0;
}

