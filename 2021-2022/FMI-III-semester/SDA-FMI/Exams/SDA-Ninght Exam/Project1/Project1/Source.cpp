

//
//int main() {
//	int n;
//	unordered_map<int, int> cart;
//	cin >> n;
//	int resultingClients = 0, resultingProducts = 0;
//	for (int i = 0; i < n; i++) {
//		int input = 0;
//		cin >> input;
//		cart[input]++;
//	}
//	for (const auto& x : cart) {
//		if (x.second % 10) resultingClients++;
//		resultingProducts += x.second % 10;
//	}
//	cout << resultingClients << " " << resultingProducts << endl;
//
//	return 0;
//}
//
//
//
//






#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int partition(vector<int> &stones, int start, int end) {
	int midIndex = start + (end - start) / 2;
	swap(stones[midIndex], stones[end]);

	int pivot = stones[end], pIndex = start;

	for (int i = start; i < end; ++i)
		if (stones[i] <= pivot)
			swap(stones[i], stones[pIndex++]);
	swap(stones[pIndex], stones[end]);
	return pIndex;
}

void quickSort(vector<int> &stones, int start, int end) {
	if (start >= end)
		return;
	int pivot = partition(stones, start, end);
	quickSort(stones, start, pivot - 1);
	quickSort(stones, pivot + 1, end);
}

bool isPairPresent(vector<int> &stones, int SUM) {
	int left(0), right(stones.size() - 1);

	while (left < right) {
		if (stones[left] + stones[right] == SUM)
			return true;
		else if (stones[left] + stones[right] > SUM)
			--right;
		else
			++left;
	}
	return false;
}

int main() {
	int N, i(0);
	cin >> N;

	vector<int> stones(N);
	for (; i < N; ++i)
		cin >> stones[i];

	quickSort(stones, 0, N - 1);

	for (const auto &stone : stones)
		if (isPairPresent(stones, stone))
			return cout << "true", 0;
	return cout << "false", 0;
}






/*
#include <stdio.h>
#include <unordered_map>

using namespace std;

int main() {
	int n, id, clients_waiting(0), undelivered_products(0);
	scanf("%d", &n);

	unordered_map<int, int> orders;

	while (n-- && scanf("%d", &id))
		++orders[id];

	for (const auto &x : orders) {
		if (x.second % 10)
			++clients_waiting;
		undelivered_products += x.second % 10;
	}
	return printf("%d %d", clients_waiting, undelivered_products), 0;
}




*/