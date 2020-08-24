// functionArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void written(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin>> arr[i];
	}
}

void read(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<< *(arr + i)<<" ";
	}
	cout << "\n";
}

int lenght(char *str)
{
	int counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return counter;
}

void sort(int *arr, int n)
{
	int minElementposition = 0;
	for (int i = 0; i < n-1; i++)
	{
		minElementposition = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[minElementposition] > arr[j])
			{
				minElementposition = j;
			}
		}
		swap(arr[minElementposition], arr[i]);
	}

}

int* addElement(int *arr, int n,int position,int number)
{
	int newSize = n + 1;

	for (int i = newSize; i > position; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[position] = number;
	return arr;
}

int* removeElement(int *arr, int n, int position)
{
	for (int i = position; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	return arr;
}

int main()
{
	/*int arr[100];
	int n;
	cin >> n;
	written(arr, n);
	read(arr, n);

	char str[100];
	cin.getline(str, 10);
	cout << lenght(str);
	*/

	int a[100] = {0};
	int n;
	cin >> n;
	written(a, n);

	int *add=addElement(a, n, 2, 555);
	sort(a, n+1);
	read(add, n + 1);
	

	int *remove= removeElement(a, n, 2);
	sort(a, n + 1);
	read(remove, n-1);
    return 0;
}

