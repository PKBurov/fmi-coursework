// arrayMarks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void writearr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<< arr[i]<<" ";
	}
	cout << endl;
}

int* readarr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >>arr[i];
	}
	return arr;
}

int main()
{
	int array[100];
	int n;
	cin >> n;
	int *p = readarr(array, n);
	writearr(p, n);
	
    return 0;
}

