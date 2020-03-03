// задача6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n,sum=0;
	cout << "n=";
	cin >> n;

	for (int i = 2; i<=n; i=i + 3)
	{
		cout << "value of i: " << i << endl;
		sum = sum + i;
		
	}

	cout << sum << endl;
    return 0;
}

