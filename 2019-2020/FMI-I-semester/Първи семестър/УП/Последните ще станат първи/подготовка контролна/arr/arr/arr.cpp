// arr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int arrA[50];
	int arrB[50];
	int n,br1=0, br2 = 0,br=0,problem1=0, problem2 = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arrB[i];
	}

	for (int i = 0; i < n; i++)
	{
		int check = arrA[i];
		for (int j = 0; j < n; j++)
		{
			if (check == arrB[j])
			{
				br1++;
				br++;
			}

			if (br > 1)
				problem1 = 1;
		}
		br = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int check1 = arrB[i];
		for (int j = 0; j < n; j++)
		{
			if (check1 == arrA[j])
			{
				br2++;
				br++;
			}

			if (br > 1)
				problem2 = 1;
		}
		br = 0;

	}
	//cout << br1 <<" "<<problem1<< endl;
	//cout << br2 << " " << problem2 << endl;
	if (br1 ==  n && br2 == n && problem1==0 && problem2==0 )
		cout << "yes\n";
	else
		cout << "no\n";
    return 0;
}

