// task9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>


using namespace std;


int main()
{
	unsigned int a, b;
	int addition = 0, subtraction = 0, multiplication = 0, ost = 0, division = 0;;

	char z;


	cin >> a;
	cin >> z;
	cin >> b;

	if (a > 15)  a = a - 16;
	if (b > 15)  b = b - 16;

	addition = a + b;
	if (addition > 15) addition -= 16;

	subtraction = a - b;
	if (subtraction > 15) subtraction -= 16;
	if (subtraction < 0) subtraction += 16;

	multiplication = a*b;
	if (multiplication > 15) multiplication -= 16;


	if (division > 15) division -= 16;
	if (b == 0)
		cout << "Division by zero!" << '\n';
	else
	{
		division = a / b;
		ost = a%b;
		if (z == '/')  cout << division << '\n';
		if (z == '%')  cout << division << "  OST.  " << ost << '\n';

	}

	if (z == '+')  cout << addition << '\n';
	if (z == '-')  cout << subtraction << '\n';
	if (z == '*')  cout << multiplication << '\n';



	return 0;
}
