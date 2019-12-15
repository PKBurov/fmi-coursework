// avarageChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
	char array[10][10];
	char result[100] = "";
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int avarage = 0;
	for (int i = 0; i < n; i++)
	{
		avarage=avarage+atoi(array[i]);
	}
	cout << avarage/n;

	int n = 10;
	int *pn = &n;
	cout << n << " " <<&n<<" "<< *pn << " " << pn << endl;
	

	int a[] = { 1,2,3, 4};

	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << *(a+i) << " ";
	}
	cout << endl;

    return 0;
}

