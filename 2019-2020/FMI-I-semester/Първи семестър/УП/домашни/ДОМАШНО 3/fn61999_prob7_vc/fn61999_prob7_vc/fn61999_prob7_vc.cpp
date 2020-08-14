/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 1
* @compiler VC
*
*/
/*	char str[100]="";
	char rezult[10];
	char strRezult[10];
	cin.getline(str, 100);
	
	int lenght = strlen(str);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		strRezult[n-1-i]= str[strlen(str) - i-1];
	}
	strRezult[n] = '\0';
	
	strncpy_s(rezult, str, lenght-n);
	strcat_s(strRezult, rezult);
	cout << strRezult<<endl;*/
#include<iostream>
using namespace std;

bool checkVowelConsonant(char c)
{
	
	int isLowercaseVowel, isUppercaseVowel;
	isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

	
	if (isLowercaseVowel == true || isUppercaseVowel == true)
		return true;
	else
		return false;
}
int main()
{
	char str[100];
	cin >> str;
	//cin.getline(str, 100);
	int i = 0;
	while (str[i] != '.' || str[i] != '!' || (str[i+2] ==' ' )/*&& str[i+1] != ' ')*/)
	{
		if (str[i] != ' ')
		{
			cout << checkVowelConsonant(str[i]) << " ";		
		}

		if (str[i + 2] != ' ' || str[i + 2] != '.')
		{
			cout << checkVowelConsonant(str[i]) << " ";
		}
		i++;
	}

/*
	
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			cout << checkVowelConsonant(str[i]) << " ";
			i++;
		}
	}
*/	
	//cout << checkVowelConsonant(c) << endl;
	return 0;
}