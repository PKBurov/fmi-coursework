// задача4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Vuvedete kordinatite na tochka A:"<<endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "A(" << a << ";"<<b<<")"<<endl;

	if (a == 0 ) 
	{cout << "A prinadleji na Oy" << endl;}

	if (b == 0 )
	{cout << "A prinadleji na Ox" << endl;}

	if (a == 0 && b==0)
	{
		cout << "A suvpada s centura na kordinatnata sistema" << endl;
	}

	if (a > 0)
	{
		if (b > 0)
		{
			cout << "A prinadleji na purvi kvadrant" << endl;
		}
		else 
		{
			cout << "A prinadleji na chetvurti kvadrant" << endl;
		}
	}
	else
	{
		if (b > 0) 
		{ cout << "A prinadleji na vtori kvadrant" << endl; }
		else
		{cout << "A prinadleji na treti kvadrant" << endl;}
	}
    return 0;
}

