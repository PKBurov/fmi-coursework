// задачае.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double x,a,b,c,max;
	cout << "Vuvedete x=";
	cin >> x;


	cout << "Vuvedete a=";
	cin >> a;

	cout << "Vuvedete b=";
	cin >> b;

	cout << "Vuvedete c=";
	cin >> c;

	if (a > b && a > c)
	{max = a;}
	else
	{
		if (b > c)
		{max = b;}
		else
		{max = c;}
	}

	if (x == max)
	{
		cout << "x=max=" << max;
	}
	else
	{
		cout << "x ne e ravno na max: x=" << x<<" max="<<max<<endl;
	}
    return 0;
}

