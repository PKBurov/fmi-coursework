// задача3в.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a, b;
	cout << "Vuvedete kordinatite na tochka a:" << endl;
	
	cout << "a=";
	cin >> a ;

	cout << "b=";
	cin >> b;

	cout << "A(" << a << ";"<<b<<")"<< endl;


	/*if (a >= -5 && a <= 5 && b >= -4 && b <= 6)
	{
		cout << "Tochka A prinadleji na kruga" << endl;
	}
	else
	{
		cout << "Tochka A NE prinadleji na kruga" << endl;
	}*/

	if(a*a+(b-1)*(b-1)<25)
	{
		cout << "Tochka A prinadleji na vutreshnostta na kruga" << endl;
	}
	else
	{
		cout << "Tochka A NE prinadleji na vutreshnostta na kruga" << endl;
	}

	system("pause");
    return 0;
}

