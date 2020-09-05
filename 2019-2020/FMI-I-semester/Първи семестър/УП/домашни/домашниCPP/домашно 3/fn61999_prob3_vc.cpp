/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 3
* @compiler VC
*
*/

#include<iostream>
#include <string.h> 

using namespace std;

int main()
{
	char str[10000];
	char rezult[10000];
	char strRezult[10000];
	cin.getline(str, 10000);
	
	int lenght = strlen(str);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
			strRezult[n - 1 - i] = str[strlen(str) - i - 1];	
	}
	strRezult[n] = '\0';

	strncpy(rezult, str, lenght-n);
	strcat(strRezult, rezult);
	cout << strRezult<<endl;

	return 0;
}