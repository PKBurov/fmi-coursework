#include <iostream>

using namespace std;

int** diagonalElements(int** matrix, int dimensions) {

	int** result = new int*[2];
	int diagElementsCount = 1;

	for (int i = dimensions-1; i > 0; i--)
		diagElementsCount *= i;

	result[0] = new int[diagElementsCount];
	result[1] = new int[diagElementsCount];

	int overDiagCount = 0;
	int belowDiagCount = 0;

	for (int i = 0; i < dimensions; i++)
		for (int j = 0; j < dimensions; j++)
			if (j > i)
				result[0][overDiagCount++] = matrix[i][j];

	for (int i = 0; i < dimensions; i++)
		for (int j = 0; j < dimensions; j++)
			if (j < i)
				result[1][belowDiagCount++] = matrix[i][j];
	
	return result;
}

int main() {
	int dimensions = 5;
	int** matrix = new int*[dimensions];
	for (int i = 0; i < dimensions; i++)
		matrix[i] = new int[dimensions];

	int filler = 1;
	for (int i = 0; i < dimensions; i++)
		for (int j = 0; j < dimensions; j++)
			matrix[i][j] = filler++;

	int** result = diagonalElements(matrix, dimensions);

	int diagElementsCount = 0;
	for (int i = dimensions - 1; i > 0; i--)
		diagElementsCount += i;

	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++)
			cout << matrix[i][j] << ' ';

		cout << endl;
	}


	cout << "Numbers above main diagonal:" << endl;
	for (int i = 0; i < diagElementsCount; i++)
		cout << result[0][i] << ' ';

	cout << endl;

	cout << "Numbers below main diagonal:" << endl;
	for (int i = 0; i < diagElementsCount; i++)
		cout << result[1][i] << ' ';

	cout << endl;

	delete[] result;
	delete[] matrix;

	system("pause");

	return 0;
}