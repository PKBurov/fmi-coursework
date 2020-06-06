// условен оператор.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int a;
	cout << "vuvedete chislo ";
	cin>> a;
	if (a > 5)
	{
		cout <<a<< " e po-golqmo ot 5 " << endl;
	}
	else
	{
		cout << a<< " e po-malko ot 5 " << endl;
	}

	return 0;
}

