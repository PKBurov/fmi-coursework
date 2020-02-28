// задача 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "Vuvedete chislo:" << endl;
	cout << "p=";
	int p;
	cin >> p;
	if (p % 4 == 0 && p % 7 == 0) {
		cout << "Chisloto p=" << p << " se deli na 4 ili 7" << endl;
	}
	else {
		cout << "Chisloto p=" << p << " NE se deli na 4 ili 7" << endl;
	}

	system("pause");
    return 0;

}

