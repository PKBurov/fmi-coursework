// fn61999_prob9_vc.cpp : Defines the entry point for the console application.
//



/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 9
* @compiler GCC
*
*/
#include "stdafx.h"
#include <iostream>
#include <cmath>


using namespace std;


int main()
{
	unsigned int a, b;
	int addition = 0, subtraction = 0, multiplication = 0, ost = 0, division = 0;

	char z;


	cin >> a;
	cin >> z;
	cin >> b;

	int m, n,c;
	
	if (a > 15)
	{
		m = a / 16;
		a = a - m * 16;
	}
	
	if (b > 15)
	{
		n = b / 16;
		b = b - n * 16;
	}

	if (a < 0)
	{
		a = fabs(a);
		m = a / 16;
		a = a - m * 16;
	}

	if (b < 0)
	{
		b = fabs(b);
		n = b / 16;
		b = b - n * 16;
	}


	addition = a + b;
	if (addition > 15) addition -= 16;

	subtraction = a - b;
	if (subtraction > 15) subtraction -= 16;
	if (subtraction < 0) subtraction += 16;

	multiplication = a*b;
	if (multiplication > 15)
	{
		c = multiplication / 16;
		multiplication = multiplication - c * 16;
	}
		


	if (b == 0)
	{
		cout << "Division by zero!" << '\n';
	}	
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
