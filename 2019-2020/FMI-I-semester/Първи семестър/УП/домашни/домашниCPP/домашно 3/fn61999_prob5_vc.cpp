/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 5
* @compiler VC
*
*/

#include<iostream>
using namespace std;


int lastDigit(long long n)
{
	return n % 10;
}

long long cutLastDigit(long long n)
{
	return n / 10;
}

int toBaseTen(int currentBase, long long n)
{
	int nBaseTen = 0, multiplier = 1;
	do
	{
		nBaseTen = nBaseTen + lastDigit(n) * multiplier;
		n = cutLastDigit(n);
		multiplier = multiplier * currentBase;
	} while (n > 0);
	return nBaseTen;
}

int Base(char number[])
{
	int t = 0;
	if (number[t] == '0' && number[t + 1] != '\0' && number[t + 1] != 'b' && number[t + 1] != 'x')   return 8;
	if (number[t] == '0' && number[t + 1] == 'b')   return 2;
	if (number[t] == '0' && number[t + 1] == 'x')   return 16;

	if (number[t] != '0')   return 10;
	if (number[t] == '0' && number[t + 1] == '\0')   return 10;

}

void ConvertToNumber(char arr[], int lenght)
{
	int counter = 0;
	if (Base(arr)==8) 
	{
		counter = 1;
	}
	if (Base(arr) == 2 || Base(arr) == 16)
	{
		counter = 2;
		
	}
	lenght += (counter + counter);
	for (int i = 0; i < lenght; i++)
	{
		arr[i] = arr[i + counter];
	}
}

int CharToDec(char arr[])
{
	int i = 0;
	int numbers[100];
	int NUMBER = 0;

	while (arr[i] != '\0')
	{
		switch (arr[i]) {
		case '0':numbers[i] = 0;
			break;
		case '1':numbers[i] = 1;
			break;
		case '2':numbers[i] = 2;
			break;
		case '3':numbers[i] = 3;
			break;
		case '4':numbers[i] = 4;
			break;
		case '5':numbers[i] = 5;
			break;
		case '6':numbers[i] = 6;
			break;
		case '7':numbers[i] = 7;
			break;
		case '8':numbers[i] = 8;
			break;
		case '9':numbers[i] = 9;
			break;
		};
		i++;
	}

	for (int t = 0; t < i; t++)
	{
		NUMBER += numbers[t] * pow(10, i - 1 - t);
	}

	return NUMBER;
}

int BinToDec(char arr[])
{
	int i = 2;
	int numbers[100];
	unsigned long long NUMBER = 0;

	while (arr[i] != '\0')
	{
		switch (arr[i]) {
		case '0':numbers[i] = 0;
			break;
		case '1':numbers[i] = 1;
			break;
		
		};
		i++;
	}

	for (int t = 2; t < i; t++)
	{
		NUMBER += numbers[t] * pow(10, i - 1 - t);
	}
	
	return toBaseTen(2, NUMBER);
}

int HexToDec(char arr[])
{
	int i = 2;
	int numbers[100];

	while (arr[i] != '\0')
	{
		switch (arr[i]) {
		case '0':numbers[i] = 0;
			break;
		case '1':numbers[i] = 1;
			break;
		case '2':numbers[i] = 2;
			break;
		case '3':numbers[i] = 3;
			break;
		case '4':numbers[i] = 4;
			break;
		case '5':numbers[i] = 5;
			break;
		case '6':numbers[i] = 6;
			break;
		case '7':numbers[i] = 7;
			break;
		case '8':numbers[i] = 8;
			break;
		case '9':numbers[i] = 9;
			break;
		case 'A':numbers[i] = 10;
			break;
		case 'B':numbers[i] = 11;
			break;
		case 'C':numbers[i] = 12;
			break;
		case 'D':numbers[i] = 13;
			break;
		case 'E':numbers[i] = 14;
			break;
		case 'F':numbers[i] = 15;
			break;
		};
		i++;
	}

	int nToBaseDec = 0, multiplier = 1;
	for (int k = i - 1; k >= 2; k--)
	{
		nToBaseDec = nToBaseDec + numbers[k] * multiplier;
		multiplier = multiplier * 16;
	}

	return nToBaseDec;
}

int OctToDec(char arr[])
{
	int i = 1;
	int numbers[100];
	int NUMBER = 0;

	while (arr[i] != '\0')
	{
		switch (arr[i]) {
		case '0':numbers[i] = 0;
			break;
		case '1':numbers[i] = 1;
			break;
		case '2':numbers[i] = 2;
			break;
		case '3':numbers[i] = 3;
			break;
		case '4':numbers[i] = 4;
			break;
		case '5':numbers[i] = 5;
			break;
		case '6':numbers[i] = 6;
			break;
		case '7':numbers[i] = 7;
			break;
		};
		i++;
	}

	for (int t = 1; t < i; t++)
	{
		NUMBER += numbers[t] * pow(10, i - 1 - t);
	}

	return toBaseTen(8, NUMBER);
}

int ConvertFromCharToNumber(char arr[], int lenght)
{
	int base = Base(arr);
	int NUMBER = 0;

	switch (base)
	{
		case 2:
			NUMBER = BinToDec(arr);
			break;
		case 8:
			NUMBER = OctToDec(arr);
			break;
		case 16:
			NUMBER = HexToDec(arr);
			break;
		default:
			NUMBER = CharToDec(arr);
	}
	return NUMBER;
}

char* substr(char arr[], int begin, int len)
{
	char* res = new char[len];

	for (int i = 0; i < len; i++)
	{
		res[i] = arr[begin + i];
	}	
	res[len] = 0;
	return res;
}

void getNumbersOnlySum(char arr[], int lenght)
{
	int sum = 0;
	int start = 0;
	int last = 1;
	int counter = 0;
	int position = 0;
	int n;
	long long number;
	int m = 0;

	for (int i = 0; i < lenght; i++)
	{
		if ((arr[i] == ' ' && arr[i - 1] != '+') || i + 1 == lenght)
		{
			if (i > 0)  last = i;
			counter = last - start;
			if (i + 1 == lenght)
			{
				counter++;
			}
			n = strlen(substr(arr, start, counter));

			number = ConvertFromCharToNumber(substr(arr, start, counter), n);
			start = last + 3;
			sum += number;
		}
	}
	cout << sum;
}
int main()
{
	char arr[10000];
	cin.getline(arr, 10000, '\n');
	int n = strlen(arr);
	long numbers[250];

	getNumbersOnlySum(arr, n);
	
	cout << '\n';
	return 0;
}
