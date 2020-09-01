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
using namespace std;

int main()
{
	unsigned int n;
	cin >> n;

	int arr[1000];
	int remainder0[1000];
	int remainder1[1000];
	int remainder2[1000];
	int remainderOther[1000];

	int index0 = 0;
	int index1 = 0;
	int index2 = 0;
	int indexOther = 0;
	int i = 0;

	int flag0 = 0;
	int flag1 = 0;
	int flag2 = 0;


	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int t = 0; t < n; t++)
	{
		if (arr[t] % 3 == 0)
		{
			remainder0[index0] = arr[t];
			index0++;
		}

		if (arr[t] % 3 == 1)
		{
			remainder1[index1] = arr[t];
			index1++;
		}

		if (arr[t] % 3 == 2)
		{
			remainder2[index2] = arr[t];
			index2++;
		}

		if (arr[t] % 3 != 2 && arr[t] % 3 != 1 && arr[t] % 3 != 0)
		{
			remainderOther[indexOther] = arr[t];
			indexOther++;
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
			flag2 = 1;
		}
		else
		{
			cout << " " << remainder2[i];
			flag2 = 1;
		}
		
	}

	for (i = 0; i < indexOther; i++)
	{
		if (i == 0 && flag0 == 0 && flag1 == 0 && flag2==0)
		{
			cout << remainderOther[i];
		}
		else
		{
			cout << " " << remainderOther[i];
		}
	}
	cout << '\n';
	return 0;
}

