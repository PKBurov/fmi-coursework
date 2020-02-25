// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	int max=-9999999999/* vuvejdame super malko chislo */, min = 9999999/* vuvejdame super golqmo chislo */;
	cin >> n;
	int number;
	for (int i = 0; i < n; i++)
	{
		
		cin >> number;
		if (number > max)
			max=number;

		if (number < min)
			 min=number;
	}
	cout << min << "," << max<<endl;
    return 0;
}

