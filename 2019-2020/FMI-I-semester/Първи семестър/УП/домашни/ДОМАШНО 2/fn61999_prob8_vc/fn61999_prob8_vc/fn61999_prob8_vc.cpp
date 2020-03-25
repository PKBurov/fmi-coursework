/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 8
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

bool check(int number, int k)
{
	int n = count(number);
	int flag = 0;
	int check;
	for (int i = 0; i < n; i++)
	{
		check = number % 10;
		if (check > k - 1)
			flag = 1;

		number = number / 10;
	}

	if (flag == 1)
		return false;

	if (flag == 0)
		return true;
}

int main()
{
	int n, m, k, suma = 0;
	int nCount, mCount;
	int last;

	cin >> n >> m >> k;

	nCount = count(n);
	mCount = count(m);

	int numberOne, numberTwo;
	int rezult[100];
	int p = fmax(nCount, mCount);
	int small;

	if (nCount != mCount)
		small = fmin(nCount, mCount);
	else
		small = nCount - 1;

	int q = 0;
	int rezultNumber;

	if (check(n, k) == 0 || check(m, k)==0)
	{
		cout << "Bad input data!\n";
		return 0;
	}
	else
	{
		for (int i = 0; i < small; i++)
		{
			numberOne = n % 10;
			numberTwo = m % 10;
			rezultNumber = numberOne + numberTwo;

			if (q == 1)
			{
				rezultNumber += 1;
				q = 0;
			}

			if (rezultNumber < k)
				rezult[i] = rezultNumber;
			else
			{
				rezult[i] = rezultNumber % k;
				q = 1;
			}

			n = n / 10;
			m = m / 10;
		}

		numberOne = n % 10;
		numberTwo = m % 10;

		rezultNumber = numberOne + numberTwo;
		if (rezultNumber + q < k)
		{
			rezult[small] = rezultNumber + q;

		}
		else
		{
			
				last = numberOne + numberTwo + q;
				if (last >= k)
				{

					rezult[small] = last%k;
					rezult[small + 1] = 1;
					q = 1;

				}
				else
				{
					rezult[small] = last;
					q = 0;
				}
			
		}

		if (last >= k)
			cout << 1;

		for (int j = p - 1; j >= 0; j--)
		{
			cout << rezult[j];
		}

		cout << "\n";
	}


	return 0;
}