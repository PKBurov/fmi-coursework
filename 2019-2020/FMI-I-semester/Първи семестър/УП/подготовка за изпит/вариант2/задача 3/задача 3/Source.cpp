/*
Задача 3. 
а) Да се напише функция, която сравнява два масива от цели числа поелементно по следния начин.Казваме, че масивът a = (a0, a1, ..., an - 1) предхожда масива b = (b0, b1, ... bm - 1), ако n ≤ m и a0< b0, a1 < b1, ... an - 1 < bn - 1. Функцията да връща - 1, ако първият масив предхожда втория, 1, ако вторият предхожда първия, 0, ако двата масива съвпадат и 2, ако нито един от двата масива не предхожда другия.
б) Да се напише функция, която в дадена матрица от цели числа проверява дали има ред, който предхожда всички останали редове.
*/

#include<iostream>
#include<cmath>

using namespace std;

int count(int number)
{
	int counter = 1;
	while (number > 0)
	{
		number = number / 10;
		if (number != 0)
			counter++;
	}

	return counter;
}

int compare(int array[][20], int maxElements, int n, int m)
{
	int i = 0;
	int a, b;

	int difference = 0;
	int aIssmalerThanB = 0;
	int bIssmalerThanA = 0;
	int equal = 0;
	while (i<maxElements)
	{
		a = array[0][i];
		b = array[1][i];			
		
			difference = a - b;
			if (difference < 0)	aIssmalerThanB++;
			if (difference > 0) bIssmalerThanA++;
			if (difference == 0) equal++;
			
		i++;
		//cout << a << " " << b << endl;

	}
	int flag = false;

	if (aIssmalerThanB == maxElements && n <= m)
	{
		flag = true;
		return -1;
	}

	if (bIssmalerThanA == maxElements && m <= n ) 
	{
		flag = true;
		return 1;
	}

	if (equal == maxElements && m==n) 
	{
		flag = true;
		return 0;
	}
	
	if (flag == false)
	{
		return 2;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	int maxElements = fmax(m, n);
	int array[50][100]= { 0 };
	int j = 0;


	for (j = 0; j < n; j++)
	{
		for (int t = 0; t < 2; t++)
		{
			cin >> array[j][t];
		}
	}

	cout << compare(array, maxElements,n,m) << endl;
	return 0;
}