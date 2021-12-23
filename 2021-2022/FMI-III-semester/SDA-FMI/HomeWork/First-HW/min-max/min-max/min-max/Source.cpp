#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int z;
	int* prices;
	cin >> z;
	prices = new int[z];

	for (int n = 0; n < z; n++){
		cin >> prices[n];
	}

	int profit = 0;
	int j = 0;

	for (int i = 1; i < z; i++){
		if (prices[i - 1] > prices[i]) {
			j = i;
		}
		if (prices[i - 1] <= prices[i] && (i + 1 == z || prices[i] > prices[i + 1])){
			profit += (prices[i] - prices[j]);
		}
	}
	cout << profit;
	delete[] prices;

	return 0;
}
// 