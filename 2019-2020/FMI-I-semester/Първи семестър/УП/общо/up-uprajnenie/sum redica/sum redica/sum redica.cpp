// sum redica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

long long Factorial(int number)
{
	int factorial = 1;
	for (int i = number;i > 0;i--)
		factorial *= i;

	return factorial;
}

int Power(int x, int power)
{
	int result = 1;
	for (;power >= 1;power--)
		result *= x;

	return result;
}

double Sum(int x, int steps) 
{
	double sum = 0;
	for (int i = 0;i <= steps;i++)
		sum =sum + (double) Power(x, i) / Factorial(i);
	return sum;
}

/*
bool can_form_triangle(double a, double b, double c)
{
	bool result = true;
	//bool isValid=(a>0)&&(b>0)&&(c>0);
	//bool result = (a + b > c) && (a + c > b) && (b + c > a);

	if (a + b > c)
		result = result && true;
	else result = result && false;

	if (a + c > b)
		result = result && true;
	else result = result && true;
	
	if (b + c > a)
		result = result && true;
	else result = result && true;

	return 
}
*/


int main()
{
	
	cout << Sum(3,2) << endl;
	//cout << can_form_triangle(3,4,5) << endl;
    return 0;
}

