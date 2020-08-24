// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int count(int number)
{
	int counter = 0;
	if (number == 0) counter = 1;
	while (number>0)
	{
		counter++;
		number /= 10;
	}
	return counter;
}

char* convertToChar(int number)
{
	//char str[100];
	int countDigits = count(number);
	char *str=new char[countDigits - 1];
	int digit = 0;
	
	int i = 0;
	while (number)
	{
		digit = number % 10;
		str[countDigits - i-1] = (char)(digit + '0');
		number /= 10;
		i++;
	}
	str[countDigits] = '\0';
	return str;
}

int main()
{
	int n;
	cin >> n;
	cout << convertToChar(n) << endl;
	
    return 0;
}

