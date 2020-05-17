#include<iostream>

using namespace std;
int matrix[10][10], n;

void Read();
void Print(int permutation[]);
void Permutation(int permutation[], int matrix_size);

int main()
{
	Read();
	int permutation[10];
	for (int i = 0; i < 10; i++)
	{
		permutation[i] = i;
	}
	Permutation(permutation, n);
}
void Read() {
	cin >> n;
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter a number!" << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			if (!cin) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Please enter a number!" << endl;
				exit(1);
			}
		}
	}
}
void Print(int permutation[]) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[permutation[i]][j] << " ";
		}
		cout << endl;
	}cout << endl;
}
void Permutation(int permutation[], int matrix_size) {
	bool flag = false;
	if (matrix_size == 1) {
		for (int i = 1; i < n; i++) {
			if (matrix[permutation[i]][i] < matrix[permutation[i - 1]][i - 1]) flag = true;
		}
		//Outputs all Answers
		if (flag == false) { cout << "Answer:" << endl; Print(permutation); return; }
	}if (matrix_size > 1) {
		for (int i = 0; i < matrix_size; i++) {
			Permutation(permutation, matrix_size - 1);
			if (matrix_size % 2 == 1)
				swap(permutation[0], permutation[matrix_size - 1]);
			else
				swap(permutation[i], permutation[matrix_size - 1]);
		}
	}
}
/*5 4 3 8 0 6
9 4 5 1 0 8
8 5 8 0 6 1
0 9 6 8 4 2
6 1 0 2 6 1
2 1 8 4 2 6*/
