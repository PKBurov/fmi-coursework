// задача3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool DataValidator(int dd, int mm, int yyyy)
{
	
	if (dd > 0 && dd < 28 && mm == 2) /*february*/
		return true;
	else 
		if (dd == 29 && mm == 2 && (yyyy % 4 == 0 || yyyy % 100 == 0 || yyyy % 400 == 0)) /*leap year*/
		return true;
	    else 
		   if (dd > 0 && dd < 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11) && yyyy > 0)
		   return true;
	       else 
		     if (dd > 0 && dd <= 31 && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && yyyy > 0)
		     return true;
	         else
		     return false;
}



int main()
{
	int dd, mm, yyyy,trueFalse;
	cout << "Input data(dd.mm.yyyy):"<<endl;
	cout << "day:";
	cin >> dd;
	cout << "month:";
	cin >> mm;
	cout << "year:";
	cin >> yyyy;
	cout << dd << "." << mm << "." << yyyy << endl;
	
	trueFalse = DataValidator(dd, mm, yyyy);
	cout << trueFalse << endl;
    return 0;
}

