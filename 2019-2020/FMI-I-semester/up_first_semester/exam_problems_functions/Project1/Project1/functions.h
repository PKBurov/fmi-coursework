#pragma once
#include<iostream>

//UniFunctions
int Strlen(const char* s)
{
	int i = 0;
	while (s[i])i++;
	return i;
}
int Min(int a, int b)
{
	return a < b ? a : b;
}
//1. Сортиране на два вече сортирани масива и връщане на 3ти
int* NewArr(int* firstArr, int* SecondArr,int arr_size) {
	//Cheking
	if (firstArr == nullptr || SecondArr == nullptr || arr_size < 0) { return nullptr; }
	//Creating Dynamiclly array
	int new_size = (2 * arr_size);
	int* newArr = new int[new_size];
	//Populating array:
	for (int i = 0; i < new_size; i++)
		newArr[i] = {0};
	//Sorting
	int j = 0,i = 0,k = 0;
	while (i < arr_size && j < arr_size){
		if (firstArr[i]<SecondArr[j])
			newArr[k++] = firstArr[i++];
		else
			newArr[k++] = SecondArr[j++];
	}
	while (i< arr_size){
		newArr[k++] = firstArr[i++];
	}
	while (j< arr_size){
		newArr[k++] = SecondArr[j++];
	}
	return newArr;
}
void Output(int* result, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		std::cout << result[i] << std::endl;
	}
}
void Delete(int* arr) {
	delete[]arr;
}

//2. Транспониране на матрица:

int** transpose(int** matrix, int size)
{
	//Create Transpose Matrix
	if (matrix == nullptr || size < 0) { return nullptr; }
	int** t = new int* [size];
	for (int i = 0; i < size; i++)
		t[i] = new int[size];
	//Populate
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			t[i][j] = {0};
	//Transposing
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = t[j][i];
			t[j][i] = temp;
		}
	}
	return t;
}
int** Create(int row_col_Count) 
{
	int** a = new int* [row_col_Count];
	for (int i = 0; i < row_col_Count; i++)
		a[i] = new int[row_col_Count];
	return a;
}
void InputMatrix(int row_col_Count, int** matrix)
{	
	for (int i = 0; i < row_col_Count; i++)
		for (int j = 0; j < row_col_Count; j++)
			std::cin >> matrix[i][j];
}
void Delete(int row_col_Count, int** arr)
{
	for (int i = 0; i < row_col_Count; i++)
		delete[] arr[i];
	delete[]arr;
}
//3. Запълнен триъгълник със символи(Не знам как точно да центрирам):
/*
void rectangle(int n, int m, char symbol)
{
	center();
	//Up & Down:
	int ctr_Up = 0, ctr_Dwn = 0;
	for ( int i = 0; i < n; i++){
		std::cout << symbol << std::endl;
	for (int j = 0; j < length; j++)
	{

	}
	//The two Sides:
	for (int i = 0; i < m; i++){

	}
	for (int j = 0; j < length; j++)
	{

	}
	//Fill Rectangle
	;
}
*/
//4. К-тата цифра:
int DigitPos(long n, int k) {
	int digit = 0, digit_counter = 0, counter = 0;
	long int devisitor = 1000000000,number=0;
	number = n;
	do
	{
		digit= n % 10;
		n = n / 10;
		digit_counter++;
	
	} while (n);
	n = number;
	//Tova e algoritama
	if (digit_counter == 10) {
		do
		{
			if (counter == k-1) {
				do
				{
					number = digit % 10;
					digit = digit / 10;

				} while (digit);
				digit = digit % 10;
				return number;
			}
			digit = n % devisitor;
			devisitor = devisitor / 10;
			counter++;

		} while (n);
	}
	//// Tova e posle tova se kopi peistva 9 puti kato promenqsh kolko e devisitora!
	return -1;
}

//5. Дали има думата word
bool doExist(char* symbols, char* word) {
	int curr = 0;
	for (int i = 0;symbols[i]!='\0'; i++){
		if (symbols[i] == word[curr]) {
			if (word[curr + 1] == '\0') {
				return true;
			}
			curr++;
		}
		else curr = 0;
	}
	return false;
}
//6. От големи в малки и обратното
void Revert(char s[])
{
	int size = Strlen(s);
	for (int i = 0; i < size; i++) {
		if ((int)s[i] >= (int)'a' && (int)s[i] <= (int)'z') {
			s[i] -= 'a' - 'A';
		}
		else {
			if ((int)s[i] >= (int)'A' && (int)s[i] <= (int)'Z') {
				s[i] += 'a' - 'A';
			}
		}
	}
}