// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double maximum( double a[], int SIZE)
{
	
	double max = a[0];
	
	for (int i = 1; i < SIZE; i++)
		if (a[i] > max) max = a[i];
	return max;
}

double minimum(double a[], int SIZE)
{

	double min = a[0];

	for (int i = 1; i < SIZE; i++)
		if (a[i] < min) min = a[i];
	return min;
}

int main()
{
	int n;
	const int SIZE = 100;
	double arr[SIZE];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maximum(arr, n) << endl;
	cout << minimum(arr, n) << endl;
    return 0;
}

