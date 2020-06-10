// fn61999_prob8_vc.cpp : Defines the entry point for the console application.
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
* @task 8
* @compiler GCC
*
*/

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int number, ostNumber, fifty, twenty, ten, five, two, one;
	cin >> number;

	cout << number << " = ";

	fifty = number / 50;
	ostNumber = number - fifty * 50;
	if (fifty != 0) cout << fifty << "*" << 50 << " + ";

	twenty = ostNumber / 20;
	ostNumber = ostNumber - twenty * 20;
	if (twenty != 0) cout << twenty << "*" << 20 << " + ";

	ten = ostNumber / 10;
	ostNumber = ostNumber - ten * 10;
	if (ten != 0) cout << ten << "*" << 10 << " + ";

	five = ostNumber / 5;
	ostNumber = ostNumber - five * 5;
	if (five != 0) cout << five << "*" << 5 << " + ";

	two = ostNumber / 2;
	ostNumber = ostNumber - two * 2;
	if (two != 0) cout << two << "*" << 2 << " + ";

	one = ostNumber;
	if (one != 0) cout << one << "*" << 1 << '\n';;



	return 0;
}




