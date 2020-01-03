// bynary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int number,count=0,last,k;
	cin >> number;
	int p;
	
	int ost[100];
	p = number / 2;
	int first=number % 2;
	int i = 0;
	while (p > 2)
	{
			ost[i] = p % 2; 
			k = p / 2;
			if (k < 2)
			{
				last = k;
			}
			if (k == 0)
			{
				last = k;
			}


			count++;
			i++;
		p= p / 2;
		
	}
	
	//cout << last ;
	for (int j = count - 1; j >=0; j--)
	{
		cout << ost[j];
	}
	
	cout << first;
    return 0;
}

