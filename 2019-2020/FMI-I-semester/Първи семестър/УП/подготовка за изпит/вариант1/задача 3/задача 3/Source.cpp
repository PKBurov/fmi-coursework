#include<iostream>
#include<cmath>

using namespace std;
/*
Задача 3. 
а) Да се напише функция, която сравнява два масива от цели числа лексикографски (като низове). Казваме, че масивът a = (a0, a1,..., an-1) лексикографски 
предхожда масива b = (b0, b1, ... bm-1), ако има число k ≤ n, така че a0= b0, a1 = b1, ... ak-1 = bk-1, но ak < bk или k = n < m. 
Функцията да връща 
-1, ако първият масив предхожда втория, 
1, ако вторият предхожда първия и 
0 ако двата масива съвпадат.
б) Да се напише функция, която в дадена матрица намира номерата на тези редове, които са съответно лексикографски най-малък и най-голям.
*/

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

int compare(int array[][100],int maxElements)
{
	int i=0;
	int a, b;
	int difference=0;

	while(i<maxElements)
	{
		a = array[0][i];
		b = array[1][i];
		int counterA = count(a);
		int counterB = count(b);

			difference = a - b;
			if (difference < 0) return -1;
			if (difference > 0) return 1;
			if (difference == 0)
			{
				i++;
			}
		//cout << a << " " << b << endl;

	}
	return 0;
	
}
int main()
{
	int n, m;
	cin >> n>>m;
	int maxElements=fmax(m, n);
	int array[50][100];
	int j = 0;

	for (int i = 0; i < 2; i++)
	{
		for (j = 0; j < maxElements; j++)
		{
		 array[i][j] =0;
		}
	}

		for ( j = 0; j < n; j++)
		{
			cin >> array[0][j];
		}

		for ( j = 0; j < m; j++)
		{
			cin >> array[1][j];
		}
	
	cout<<compare(array, maxElements)<<endl;

	return 0;
}