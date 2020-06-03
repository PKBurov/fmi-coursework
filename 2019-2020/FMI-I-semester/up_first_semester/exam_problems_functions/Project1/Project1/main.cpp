#include<iostream>
#include"functions.h"

using namespace std;

int main()
{
	//Транспониране на матрица:
	
	int n;
	cin >> n;
	Create(n);
	int** matrix = Create(n);
	InputMatrix(n, matrix);
	int** result = transpose(matrix,n);
	Delete(n, matrix);
	cout << endl;
	for (int i = 0; i < n; i++){
		for (int J = 0; J < n; J++)
		{
			cout << result[i][J]<<" ";
		}
		std::cout << std::endl;
	}
	Delete(n, result);






	
	//Сортирнае на масиви:
	
	const int SIZE = 10;
	int SORTEDSIZE = 20;
	int firstArr[SIZE] = { 1,3,5,7,9,11,13,15,17,19 };
	int secondArr[SIZE] = { 0,2,4,6,8,10,12,14,16,18 };
	int* Result = NewArr(firstArr, secondArr, SIZE);
	Output(Result, SORTEDSIZE);
	Delete(Result);
	







	//Запълнен триъгълник със символи(Не знам как точно се центрира):
	/**/
	//К-тата цифра
	/*
	long int number = 1234567892;
	int k = 7;
	cout << DigitPos(number, k);
	*/
	char a = 'a';
	char z = 'z';
	char A = 'A';
	char Z = 'Z';
	cout << (int)a << endl << (int)z << endl << (int)A << endl << (int)Z << endl;


	return 0;
}