// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

// functions for stringa to play with:
// - strlen
// - strcat, strncat (strcat_s, strncat_s)
// - strcpy, strncpy (strcpy_s, strncpy_s)
// - strcmp
// - strchr
// - strrchr
// - strstr

void no_up_string(int n, char* str)
{
	
	for (int i = 0; i < n; i++)
	{
		//cout << str << endl;
		if (str[i] == 'u' && str[i + 1] == 'p')
		{
			for (int j = i; j < n - 2; j++)
			{
				str[j] = str[j + 2];
			}
			i--;
			str[n - 1] = '\0';
			str[n - 2] = '\0';
			n -= 2;
			
		}
	}
	cout << str << endl;
}

int main()
{
	char str[] = "upvdbbbfupbupup";
	no_up_string(100, str);
	system("pause");
		
	
	return 0;
}



