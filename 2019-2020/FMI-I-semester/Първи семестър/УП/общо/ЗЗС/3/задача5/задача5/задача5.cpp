// задача5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool sumChetnoKratnoNa3(int a)
{
	int sum = 0;
	while (a != 0) {
		sum = sum + a % 10;
		a =a/ 10;
	}
	
	if (sum % 3 == 0)
		return true;
	else
		return false;
}

int main()
{
	int p;
	cout << "Input number:";
	cin >> p;
	cout << sumChetnoKratnoNa3(p) << endl;
    return 0;
}

