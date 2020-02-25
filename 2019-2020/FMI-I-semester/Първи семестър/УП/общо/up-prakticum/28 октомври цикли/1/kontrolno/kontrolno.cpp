// kontrolno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int hours, dayOfWeek=0;
	cout << "hours=";
	cin >> hours;
	cout << "Day:";
	cin >> dayOfWeek;
	double price=1;

	switch (dayOfWeek) {
	case 1:
		price = hours * 6;
			break;
	case 2:
		price = hours * 4.5;
		    break;
	case 3:
		price = hours * 6;
		break;
	case 4:
		price = hours * 6;
		break;
	case 5:
		break;
	case 6:
		price = hours * 7.25;
		break;
	case 7:
		price = hours * 7.45;
		break;
	default:
		cout << "wrong input:" << endl;
			break;
	}

	cout << price << endl;
    return 0;
}

