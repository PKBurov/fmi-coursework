#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int firstArrSize, secArrSize;
	int uniqueSum = 0;
	int* firstArr;
	int* secArr;


	cin >> firstArrSize;
	firstArr = new int[firstArrSize];
	for (int i = 0; i < firstArrSize; i++){
		cin >> firstArr[i];
	}

	cin >> secArrSize;
	secArr = new int[secArrSize];
	for (int i = 0; i < firstArrSize; i++) {
		cin >> secArr[i];
	}


	for (int i = 0; i < firstArrSize; i++){
		for (int j = 0; j < secArrSize; j++){
			if (firstArr[i] == secArr[j])
			{
				uniqueSum = uniqueSum + firstArr[i];
			}
		}
	}
	cout << uniqueSum;
	delete[] firstArr;
	delete[] secArr;
	

}
