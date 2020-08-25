#include<iostream>
using namespace std;
/*Напишете програма на C++, която приема от стандартния вход число (градуси) и символ(тип температурна скала). Програмата трябва да превърне въведеното температура от 
градуси по целзий в съответно:   
• градуси по Фаренхайт, ако въведеният символ е F;   
• градуси по Келвин, ако вуведеният символ е K; 
Ако въведеният символ не съответства на нито един от по-горе посочените, програмата трябва да приключи изпълнението си с код за грешка и да информира потребителя за това.   */

int convertToNumber(char str[],int lenght)
{
	int number=0;
	int temp = 0;
	int counter = 0;
	for (int i = lenght - 3; i >=0; i--)
	{
		temp=str[i]-'0';
		number += temp*pow(10, counter);
		counter++;
	}

	return number;
}

int main()
{
	char arr[100];
	cin.getline(arr, 100);
	int lenght = strlen(arr);
	

	char sign = arr[lenght - 1];
	double number=convertToNumber(arr, lenght);

	if (sign == 'F')
	{
		cout << number*1.8 + 32 << endl;
	}

	if (sign == 'K')
	{
		cout << number+273.15 << endl;
	}
	return 0;
}