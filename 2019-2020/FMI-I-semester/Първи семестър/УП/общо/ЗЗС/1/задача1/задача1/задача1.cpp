// задача1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;


int main()
{
	int years, days, minutes, seconds;
	
	cout << "vuvedete navurshenite godini ";
	cin >> years;
	cout << "izminali godini " << years << endl;
	
	days = years * 365;
	cout << "izminali dni " << days << endl;

	minutes = days * 24 * 60;
	cout << "izminali minuti " << minutes << endl;

	seconds = minutes * 60;
	cout << "izminali sekundi " << seconds << endl;

	
    return 0;
}

