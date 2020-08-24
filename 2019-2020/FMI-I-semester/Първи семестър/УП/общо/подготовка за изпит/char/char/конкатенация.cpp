// char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char array[10][10];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	char result[500]="";
	for (int i = 0; i < n; i++)
	{
		strcat_s(result, array[i]);
	}
	cout << result << endl;
    return 0;
}

