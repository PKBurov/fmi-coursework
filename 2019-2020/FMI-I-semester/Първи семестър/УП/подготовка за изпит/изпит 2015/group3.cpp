// group3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
/*
За всеки елемент на случайно инициализиран с числа от интервала [-5; 5] масив от 10 елемента да се изведе сумата на елемента с двата следващи го 
(при недостиг на елементи в края на масива да се вземат елементи от началото – например 10-ия елемент трябва да се събере с 1ия и 2ия). 
Първо да се изведе масива. Всеки елемент от изхода да е отделен от другия с празно място.
*/

void inputArray(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
}

void printArray(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		cout<< arr[i]<<" ";
	}
	cout << endl;
}

int main()
{
	int arr[100];
	int sum[100];
	inputArray(arr);

	for (int i = 0; i < 10; i++)
	{
		if (i != 8 && i != 9)
		{
			sum[i] = arr[i] + arr[i + 1] + arr[i+2];
		}

		if(i==8)
		{
			sum[i] =arr[i]+ arr[i + 1] + arr[0];
		}

		if (i == 9)
		{
			sum[i] = arr[i] + arr[0]+arr[1];
		}
	}

	printArray(sum);
    return 0;
}
//1 0 3 0 2 0 5 0 -5 -4
