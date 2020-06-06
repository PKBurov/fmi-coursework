// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include <cstring>

using namespace std;
/*
Напишете функция, която по подаден масив от символи връща броя на думите, които се съдържат в него
Пример
char* array = "V sabota imame kontrolno"
Когато подадете този масив на вашата функция тя трябва да върне стойност 4
*/



int countArr( char *s)
{
	int count = 1;
	for (int n = 0; *s != '\0'; s++)
	{
			if (*s == ' ')
				count++;
			n++;
	}
		
	return count;
}

int countArray(char arr[100])
{
	int count = 1;
	int i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == ' ')
			count++;
		i++;
	}

	return count;
}

int main()
{	
	char* arr = "V sabota imame kontrolno";
	cout << countArr (arr)<< endl;

	char array[100]= "V sabota imame kontrolno";
	//cin >> array;

	cout << countArray(array) << endl;

    return 0;
}

