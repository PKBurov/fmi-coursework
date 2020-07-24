#include <iostream>
#include <string>
using namespace std;

bool rowContains(int sudoku[][9], int row, int num) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == num) return true;
	}
	return false;
}

bool colContains(int sudoku[][9], int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == num) return true;
	}
	return false;
}

bool valuesAreFilled(int values[], int n) {
	for (int i = 0; i < n; i++) {
		if (values[i] != 1) return false;
	}
	return true;
}

bool solvedBox(int sudoku[][9], int boxId) {
	int values[9] = {0};
	int startRow = (boxId/3)*3;
	int startCol = (boxId%3)*3;

	for (int i = startRow; i < startRow+3; i++) {
		for (int j = startCol; j < startCol+3; j++) {
			if (sudoku[i][i] > 0) {
				values[sudoku[i][j]-1]++;
			}
		}
	}

	return valuesAreFilled(values, 9);
}

bool solvedRow(int sudoku[][9], int row) {
	int values[9] = {0};

	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] > 0) {
			values[sudoku[row][i]-1]++;
		}
	}

	return valuesAreFilled(values, 9);
}

bool solvedCol(int sudoku[][9], int col) {
	int values[9] = {0};

	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] > 0) {
			values[sudoku[i][col]-1]++;
		}
	}

	return valuesAreFilled(values, 9);
}


int x = 0;
bool solved(int sudoku[][9]) {
	x++;
	if (x%10 == 0) cout<<"Trying for the "<<x<<" time!"<<endl;
	for (int i = 0; i < 9; i++) {
		if (!solvedRow(sudoku, i) || !solvedCol(sudoku, i) || !solvedBox(sudoku, i)) return false;
	}
	return true;
}

bool solveHelper(int sudoku[][9], int i, int j) {
	int nextJ = (j+1) % 9;
	int nextI = j+1 > 8 ? i + 1 : i;

	if (i > 8) return solved(sudoku);

	if (sudoku[i][j] > 0) return solveHelper(sudoku, nextI, nextJ);
	else {
		for (int num = 1; num <= 9; num++) {
			if (rowContains(sudoku, i, num) || colContains(sudoku,j,num)) continue;
			sudoku[i][j] = num;
			if (solveHelper(sudoku,nextI, nextJ)) {
				return true;
			}
		}
		sudoku[i][j] = 0;
	}
	return false;
}

void solve (int sudoku[][9]) {
	solveHelper(sudoku, 0, 0);
}

int main ()
{
	int sudoku[9][9] = {
		{8,7,1,   0,0,0,   5,6,0},
		{0,0,6,   0,0,0,   0,0,0},
		{2,0,0,   0,6,0,   4,0,8},
		
		{0,0,0,   5,4,7,   0,1,0},
		{0,0,2,   0,8,0,   7,0,0},
		{0,4,0,   1,2,9,   0,0,0},
		
		{3,0,7,   0,9,0,   0,0,4},
		{0,0,0,   0,0,0,   6,0,0},
		{0,8,4,   3,0,0,   2,9,7},
	};

	solve(sudoku);
	
	cout<<"RESULT:"<<endl<<" ______ ______ ______ "<<endl;
	for (int i = 0; i < 9; i++) {
		cout<<"|";
		for (int j = 0; j < 9; j++) {
			cout<<sudoku[i][j]<<" ";
			if (j%3==2) {
				cout<<"|";
			}
		}
		cout<<endl;
		if (i%3==2) {
			cout<<"|______|______|______|"<<endl;
		}
	}


    return 0;
}