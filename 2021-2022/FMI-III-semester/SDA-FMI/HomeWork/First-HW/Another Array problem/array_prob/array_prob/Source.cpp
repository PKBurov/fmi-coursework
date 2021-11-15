#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000] = { 0 };
int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++){
		int a = 0;
		cin >> a;
		arr[a]++;
	}
	for (int i = 0; i < 100000; i++){
		if (arr[i] > 0) {
			cout << i << " ";
		}
	}
	return 0;
}