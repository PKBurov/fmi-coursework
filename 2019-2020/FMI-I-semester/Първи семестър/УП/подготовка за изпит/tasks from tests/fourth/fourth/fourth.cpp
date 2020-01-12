// fourth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

bool searchX(int x, int number)
{
	bool isFaund = false;
	int check = 0;
	if (x == number && x == 0)
	{
		isFaund = true;
	}

	while (number)
	{
		check = number % 10;
		if (x == check)
		{
			isFaund = true;
		}
		number = number / 10;
	}
	return isFaund;
}
int main()
{
	//int number;
	//cin >> number;
//Да се напише програма, която проверява дали в дадено естествено число n има две еднакви цифри
	/*
	int digit = 0, digitCheck=0,counter = 0;
	int temp = number;
	bool flag = false;
	while (number)
	{
		temp = temp / 10;
		digit = number % 10;
		while (temp)
		{
			digitCheck = temp % 10;
				if (digitCheck == digit)
				{
					counter++;
				}
				if (counter > 0)
					flag = true;

				counter = 0;
				temp = temp / 10;
		}
		number = number / 10;
	}
	cout << flag << endl;*/

	//Да се напише програма, която извежда всички цифри, които се срещат едновременно в числата m и n

	int m, n;
	cin >> m >> n;
	int tempForM=0, tempForN=0;
	bool flagM = false,flagN=false;
	int clonM = m;
	int clonN = n;

	while (clonM>0)
	{
		tempForM = clonM % 10;
		int checkFirst = clonM / 10;
		if (searchX(tempForM, checkFirst) == false)
		{
				while (clonN>0)
				{				
						tempForN = clonN % 10;
						if (tempForM == tempForN)
						{
							cout << tempForM << endl;
						}				
					clonN = clonN / 10;
				}

			clonN = n;
		}
		clonM = clonM / 10;
	}


    return 0;
}

