// for.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

bool Simple(int number)
{
	int br = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0)
			br++;
	}

	if (br == 2)
		return true;
	else
		return false;
}

int Count(int number)
{
	int n, br = 1;
	
	while (number > 0)
	{
		n = number / 10;
		if (n > 0)
			br++;
		number /= 10;
	}
	return br;


}
int main()
{
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			
		}
			
	}
	cout << "min " << min << endl;
	
	return 0;
}

