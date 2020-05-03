// fn61999_prob1_vc.cpp : Defines the entry point for the console application.
//

/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 4
* @compiler VC
*
*/

#include<iostream>
#include<cmath>
using namespace std;

int count(int number)
{
	int br = 0;
	while (number != 0)
	{
		number = number / 10;
		br++;
	}
	return br;
}


int main()
{
	int a, b,m,n,brONE=0, brTWO = 0,checkA,checka,checkB,checkb,checkFIRST=0,checkSECOND=0,countONE=0, countTWO = 0;
	cin >> a >> b;

	a=fabs(a);
	b = fabs(b);
	m = count(a);
	n = count(b);

	int oldA, oldB;
	oldA = a;
	oldB = b;

	for (int i = 0; i < m; i++)
	{
		checkA = a%10;
		checkb = b;
		for (int j = 0; j < n; j++)
		{
			checkB = checkb % 10;
			if (checkA == checkB)
			{
				brONE++;
				countONE++;
			}
			checkb = checkb / 10;
			
		}
		if (countONE>1)
			brONE = brONE - countONE +1;

		countONE = 0;
		
		a = a / 10;
	}

	
	if (brONE == m)
		checkFIRST = 1;


	for (int t = 0; t < n; t++)
	{
		checkB = oldB % 10;
		checka = oldA;
		for (int k = 0; k < m; k++)
		{
			checkA = checka % 10;
			if (checkA == checkB)
			{
				brTWO++;
				countTWO++;
			}
			checka = checka / 10;
			
			
		}
		if (countTWO>1)
			brTWO =brTWO- countTWO + 1;
		
		countTWO = 0;
		oldB = oldB / 10;
	}


	if (brTWO == n)
		checkSECOND = 1;


	if (checkFIRST == 1 && checkSECOND == 1)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	

	return 0;
}