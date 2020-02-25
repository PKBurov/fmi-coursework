// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "n=";
	int n, sum = 0;
	cin >> n;
	
	while (n != 0)
	{		 
		sum = sum + n%10;
		n = n / 10;			
	}
	
	cout << sum << endl;

    return 0;
}

