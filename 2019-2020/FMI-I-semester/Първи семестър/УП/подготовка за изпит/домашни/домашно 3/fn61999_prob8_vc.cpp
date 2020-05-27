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

int negativeNumber(int remainder)
{
	int n;
	if (remainder < 0)
	{
		n = remainder / 3;
		n = fabs(n);
		return remainder + 3 * (n + 1);
	}
}

int main()
{
	unsigned int n;
	cin >> n;

	int arr[10000];
	int arrPositive[10000];
	int remainder0[10000];
	int remainder1[10000];
	int remainder2[10000];

	int index0 = 0;
	int index1 = 0;
	int index2 = 0;
	int i = 0;

	int flag0 = 0;
	int flag1 = 0;
	

	
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			arrPositive[i] = negativeNumber(arr[i]);
		}
		else
		{
			arrPositive[i] = arr[i];
		}
	}

	for (int t = 0; t < n; t++)
	{
		if (arrPositive[t] % 3 == 0)
		{
			remainder0[index0] = arr[t];
			index0++;
		}

		if (arrPositive[t] % 3 == 1)
		{
			
			remainder1[index1] = arr[t];
			index1++;
		}

		if (arrPositive[t] % 3 == 2)
		{
			if (remainder2[t] <0)
			{
				remainder2[t] = negativeNumber(remainder2[t]);
			}
			remainder2[index2] = arr[t];
			index2++;
		}

		
	}

	for (i = 0; i < index0; i++)
	{
		if (i == 0)
		{
			cout << remainder0[i];
			flag0 = 1;
		}
		else
		{
			cout << " " << remainder0[i];
			flag0 = 1;
		}

	}

	for (i = 0; i < index1; i++)
	{
		if (i == 0 && flag0 == 0)
		{
			cout << remainder1[i];
			flag1 = 1;
		}
		else
		{
			cout << " " << remainder1[i];
			flag1 = 1;
		}
	}

	for (i = 0; i < index2; i++)
	{
		if (i == 0 && flag0 == 0 && flag1 == 0)
		{
			cout << remainder2[i];
			
		}
		else
		{
			cout << " " << remainder2[i];
		}
	}

	cout << '\n';
	return 0;
}

