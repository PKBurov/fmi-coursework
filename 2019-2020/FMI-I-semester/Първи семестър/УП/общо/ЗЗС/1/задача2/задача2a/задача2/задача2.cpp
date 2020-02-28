// задача2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double a, h;
	double S;
	cout << "Vuvedete stranata i visochinata na triugulnika"<<endl;

	cout << "stranata na triugulnika a=";
	cin >> a;

	cout << "visochinata na triugulnika h=";
	cin >> h;

	S = (a*h) / 2;
	cout << "Licheto na triugulnika e S=" << S << endl;
	
    return 0;
}

