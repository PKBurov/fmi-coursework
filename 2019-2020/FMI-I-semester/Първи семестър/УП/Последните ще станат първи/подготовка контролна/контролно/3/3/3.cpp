// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

/*
Напишете функция, която по подаден целочислен агрумен извежда ромб
Пример : х = 3
*/
void PrintRombus(int x)
{
	for (int i = 0; i < x-1; i++)
	{
		for (int j = 0; j < x - i; j++)
		{
			cout << ' ';
			
		}
		
		//cout << " *";
		cout << " *" << endl;
	
	}
	
	/*for (int i = 0; i < x ; i++)
	{
		cout << " * " ;
	}*/
	cout << endl;
	/*for (int i = x-1; i >0; i--)
	{
		for (int j = x - 1; j >0; j--)
		{
			cout << ' ';

		}
		cout << " * " << endl;

	}
	*/
}

/*
•	Разделете ромба на горна и долна част и ги печатайте с два отделни цикъла.
•	За горната част завъртете цикъл за row от 1 то n:
o	Отпечатайте n-row интервала.
o	Отпечатайте “*”.
o	Отпечатайте row-1 пъти “ *”.
•	Долната част отпечатайте аналогично на горната с цикъл от 1 до n-1.
*/



int main()
{
	int x;
	cin >> x;
	
	PrintRombus(x);
	

	return 0;
}
