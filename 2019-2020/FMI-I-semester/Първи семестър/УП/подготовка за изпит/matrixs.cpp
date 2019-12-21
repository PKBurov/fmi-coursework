// matrixs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void writeMatrix(int matrix[][10], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int matrix[][10], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout<< matrix[i][j]<<" ";
		}
		cout << '\n';
	}
}

int Diagonal(int matrix[][10], int row, int column)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == j)
			{
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

int downDiagonal(int matrix[][10], int row, int column)
{
	int sum = 0;
	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < column-1; j++)
		{
				sum += matrix[i][j];
		}
	}
	return sum;
}

int upDiagonal(int matrix[][10], int row, int column)
{
	int sum = 0;
	for (int i = 0; i < row-1; i++)
	{
		for (int j = 1; j < column; j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

int main()
{
	int matrix[10][10];
	int row, column;
	cin >> row >> column;
	writeMatrix(matrix, row, column);
	
	//printMatrix(matrix, row, column);
	cout << Diagonal(matrix,row,column) << endl;
	cout << downDiagonal(matrix, row, column) << endl;
	cout << upDiagonal(matrix, row, column) << endl;
    return 0;
}

