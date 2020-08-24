// charr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string.h>
using namespace std;
/*
Напишете програма, която кара потребителя да въведе символен низ от 15 елемента. След това програмата трябва да намери сумата на всички числа съдържащи се в масива 
(числа, не цифри!). Числата ще бъдат винаги цели и положителни и ще бъдат разделени с един или повече знаци, които не са цифри.
Пример 1 Вход: "a15aasdf100aa75" Изход: 190

Пример 2 Вход: "a15aasdf100aa75" Изход: 190

Пример 3 Вход: "115aasdf10a750а" Изход: 875
*/

int sum_numbers(char *str)
{
	int sum = 0;

	int number = 0;
	int i = 0;
	while(str[i]!='\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number =number+ str[i] - '0';
		}
		else
		{
			sum += number;
			number = 0;
		}

		i++;
	}
	sum += number;//in case when the string ends with digit we need to add number one more time

	return sum;
}

int main()
{
	char arr[100];
	cin >> arr;
	cout << sum_numbers(arr);
    return 0;
}
