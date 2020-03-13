// задача6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool proverkaN(int x)
{
	int stepen = 0;
	for (int i = 1; i <= x; i = i * 2)
	{
		if (x == i)
			stepen = 1;
	}

		if (stepen == 1)
			return true;
		else
			return false;
	
}
int main()
{
	int n;
	cout << "n=";
	cin >> n;

	cout << proverkaN(n) << endl;
	cout << "1: n is power of 2" << endl;
	cout << "0:  n is NOT power of 2" << endl;
    return 0;
}

