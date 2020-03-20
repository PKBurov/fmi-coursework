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
	int a, b,m,n,brONE=0, brTWO = 0,checkA,checka,checkB,checkb,checkFIRST=0,checkSECOND=0;
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
				brONE++;
			checkb = checkb / 10;
		}
		a = a / 10;
	}

	
	
	if (brONE == m)
		checkFIRST = 1;

	for (int i = 0; i < n; i++)
	{
		checkB = b % 10;
		checka = oldA;
		for (int j = 0; j < m; j++)
		{
			checkA = checka % 10;
			if (checkA == checkB)
				brTWO++;
			checka = checka / 10;
		}
		b = b / 10;
		
	}

	

	if (brONE == brTWO && m != n)
	{
		cout << "No\n";
		return 0;
	}

	if(brONE==brTWO)
	{
		cout << "Yes\n";
		return 0;
	}
	else
	{
		cout << "No\n";
		return 0;
	}

	return 0;
}