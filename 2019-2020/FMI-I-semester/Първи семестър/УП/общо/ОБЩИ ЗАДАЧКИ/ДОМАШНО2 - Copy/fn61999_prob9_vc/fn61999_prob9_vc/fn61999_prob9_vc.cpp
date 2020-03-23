/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 9
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

bool check(int a, int b)
{
	int m, p,k, br = 0;
	
	m = count(a);

	for (int i = 0; i < m; i++)
	{
		p = a % 10;
		k = b % 10;

		if (p == k)
			br++;
		a = a / 10;
		b = b / 10;
	}

	if (br == m)
		return true;
	else
		return false;
}

int main()
{
	int a, b;
	cin >> a >> b;

	int last, lastNumber,firstNumber;
	int p, m, n,number,checkNumber=0;

	m = count(a);
	n= count(b);
	
	int aOLD = a;

	if (n > m )
	{
		cout << "No\n";
		return 0;
	}
		

	if (m == n)
	{
		if (check(a, b) == 1)
		{
			cout << "Yes\n";
			return 0;
		}
		else
		{
			cout << "No\n";
			return 0;
		}
	}
		
	if (n == m-1)
	{
		int arr[100]; 

		firstNumber= a / 10;
		for (int i = 0; i < m; i++)
		{
			arr[i] = a % 10;
			number = a / 10;
			
			number = number*pow(10, i);
			if (number != 0)
			{
				p = i - 1;
				while (p >= 0)
				{
					number += arr[p] * pow(10, p);
					p--;

				}
				if (check(number, b) == 1)
					checkNumber = 1;

			}

			a = a / 10;

		}
		
		
	}

	last = pow(10, m - 1);
	lastNumber = aOLD %last;

	if (checkNumber == 1 || check(lastNumber, b) == 1 || check(firstNumber, b) == 1)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}