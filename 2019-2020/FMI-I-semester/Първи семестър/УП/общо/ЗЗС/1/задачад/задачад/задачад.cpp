// задачад.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	double x;
	bool trueFalse;
	cout << "Vuvedete x=";
	cin >> x;
	trueFalse = x >= 0 && x <= 1;
	cout << trueFalse <<endl;
	
	
	system("pause");
    return 0;
}

