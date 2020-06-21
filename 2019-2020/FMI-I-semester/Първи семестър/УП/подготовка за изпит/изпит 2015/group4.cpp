// group4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
/*
За случайно инициализиран масив от 16 малки латински букви да се генерира двоично число, за което 
0 = { a, b, c, d, e, f } , 
1 = {<всички останали>}. 
Да се изведе масива. 
Да се изведе числото в двоична и десетична форма
*/

using namespace std;

unsigned long long converToBinary(int arr[], int n)
{
	unsigned long long number = 0;
	int degree=0;
	for (int i = n-1; i >= 0; i--)
	{
		number += arr[i] * pow(10, degree);
		degree++;
	}

	return number;
}

unsigned long long converToDecimal(int arr[], int n)
{
	unsigned long long number = 0;
	int degree = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		number += arr[i] * pow(2, degree);
		degree++;
	}

	return number;
}
int main()
{
	char arr[100];
	cin.getline(arr,100);
	int binary[100] ;
	int i = 0;
	int counter = 0;
	while (arr[i]!='\0')
	{
		if (arr[i] == 'a' ||
			arr[i] == 'b' ||
			arr[i] == 'c' ||
			arr[i] == 'd' ||
			arr[i] == 'e' ||
			arr[i] == 'f')
		{
			
			binary[counter] = 0;
			counter++;
		}
		else
		{
			if (arr[i] != ' ')
			{
				
				binary[counter] = 1;
				counter++;
			}	
		}
		i++;
	}

	cout << "array: ";
	for (int k = 0; k < counter; k++)
	{
		cout << binary[k];
	}
	cout << endl;

	unsigned long long numberBinary = converToBinary(binary, counter);
	cout << "binary: ";
	cout<< numberBinary << endl;

	unsigned long long numberDecimal= converToDecimal(binary, counter);
	cout << "decimal: ";
	cout << numberDecimal << endl;
	//cout << 0xnumber << endl;
	//f x w v u g t v b q b t x t
	//f x w v u g t v b v q q b t x t
    return 0;
}

