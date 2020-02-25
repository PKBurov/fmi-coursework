// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{

	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	int sum = 0;
	cout << "SUM (" << a << ";" << b << ")" << endl;
	if (a < b)
	{
		for (int i = a + 1; i < b; i++) /*chislata a i b ne sa vklucheni v sumata*/
			sum = sum + i;
		cout << sum << endl;
	}
	else
	{
		cout << "ERROR a<b" << endl;
	}
	
	
    return 0;
}

