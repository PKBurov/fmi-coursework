// задача7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n,p, br=0;
	cout << "n=";
	cin >> n;

	for (int i = 1; i <= n ; i = i++)
	{
		p = pow(i, 3) + 13 * i*n + pow(n, 3);
		if (p % 5 == 0 || p % 9 == 0)
		{
			cout << p << endl;
			br++;
			cout << br<< endl;
		}


	}

	
	return 0;
}

