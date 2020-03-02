// задачан.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int main()
{
	int p;
	cout << "Vuvedete chisloto p(tricifreno i polojitelno)"<<endl;
	cin >> p;

	if (p%10 == 7 || p/10%10 == 7 || p/100== 7)
	{
		cout << "V chisloto ima cifrata 7" << endl;
	}
	else
	{
		cout << "V chisloto nqma cifrata 7" << endl;
	}


    return 0;
}

