// count.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{

/*
Броя на символите в низа

	char str[100];
	cin>>str;
	int i = 0;
	while (str[i] != '\0') i++;
	cout << i << endl;

*/

/*
Колко пъти се среща даден символ
	
	char str[100], s;
	cin >> str >> s;
	int br = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == s) br++;
		i++;
	}
	cout << br << endl;
*/


	int br = 0,flag=0, i = 0, j = 1;
	char str[100];
	cin >> str;
	
	while (str[i] != '\0')
	{
		if (str[i] != str[j])
		{
			/*int j = 0;
			while (str[i] != '\0')
			{
				if (str[i] == str[j]) br++;
				i++;
			}*/
			cout << str[i]<<" ";
			cout << br << endl;
			
		}
			
		
		i++;
	}
    return 0;
}

