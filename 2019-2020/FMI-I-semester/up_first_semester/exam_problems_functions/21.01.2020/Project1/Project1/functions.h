#pragma once
#include<istream>

//UniFunc
int Strlen(const char* s)
{
	int i = 0;
	while (s[i]) i++; // while(s[i] != '\0') i++;
	return i;

}
//int getStringSize(char* s) {
/////....+ не терминиращ елемент;
//}
int getNumberSize(int n)
{
	int size = 0;
	do
	{
		n /= 10;
		size++;
	} while (n);
	return size;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//Едно число колко цифри има
//Колко е дълъг един стринг

//1



//2
//Винаги ще има празен низ като тест;
void Revert(char s[])
{
	int size = Strlen(s);
	for (int i = 0; i < size; i++){
		if ((int)s[i] >= (int)'a' && (int)s[i] <= (int)'z'){
			s[i] -= 'a' - 'A';
		}else{
			if ((int)s[i] >= (int)'A' && (int)s[i] <= (int)'Z'){
				s[i] += 'a' - 'A';
			}
		}
	}
}

//3 Задача с матрица (динамична памет)

void transpose(int** matrix, int size) 
{
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

}




//4  Returning Matrix:
//int** returnMatrix(int**getMatrix,int size) {
//
//	int** matrix = new int* [size];
//
//	for (size_t i = 0; i < size; i++){
//		matrix[i] = new int[10];
//	}
//	for (int i = 0; i < size; i++){
//		delete[]matrix[i];
//	}
//	delete[]matrix;
//	return matrix;
//}
//



//5




//6




//7