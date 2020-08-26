// removeIntervals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>

using namespace std;
char* removeIntervals(char *str)
{
	int lenght = strlen(str);
	for(int i=0;i<lenght;i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < lenght; j++)
			{
				str[j] = str[j + 1];
			}
			lenght--;
		}
	}
	return str;

}

char* SEARCHxtOy(char *str)
{
	int lenght = strlen(str);
	for (int i = 0; i<lenght; i++)
	{
		if (str[i] == 'x')
		{
			str[i] = 'Y';
		}
	}
	return str;

}

char* substring(char *str,int start,int lenght)
{
	char *subSTR=new char[lenght];
	int last = lenght - start +2;
	int j = 0;
	for (int i = start; i<last; i++)
	{
		subSTR[j]=str[i];
		j++;
	}
	subSTR[j] = '\0';
	return subSTR;

}

int main()
{
	char str[100];
	cin.getline(str, 100);

	//cout << removeIntervals(str) << endl;
	//cout << SEARCHxtOy(str) << endl;
	cout << substring(str,1,5) << endl;
	
    return 0;
}
//ftfytxxxgyugfyx xxx
