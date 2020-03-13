// задача1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <math.h>

using namespace std;

double LiceNaKrug(double r)
{
	
	double S = 3.14*r*r;

	return S;
}

int main()
{
	double R;
	cout << "Input radius: r=";
	cin >> R;
	cout << "Surface is "<< LiceNaKrug(R) << endl;

    return 0;
}

