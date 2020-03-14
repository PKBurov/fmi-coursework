// задача8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void isPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j <= i; j++)
		{
			if (i%j == 0)
				sum = sum + j;
		}
				
		if (sum == i)
			cout << i << " ";	
	}
}

int main()
{
	int range;
	cin >> range;
	isPerfect(range);
	return 0;
}

