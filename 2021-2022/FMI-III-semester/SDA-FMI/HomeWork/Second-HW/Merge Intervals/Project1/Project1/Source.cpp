#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr) {

	sort(arr.begin(), arr.end());
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1][1] >= arr[i][0])
		{
			arr[i][0] = arr[i - 1][0];
			arr[i][1] = max(arr[i - 1][1], arr[i][1]);
			arr[i - 1][0] = -1;
			arr[i - 1][1] = -1;
		}
	}

	vector<vector<int>> res;
	for (auto x : arr)
	{
		if (x[0] != -1 and x[1] != -1) {
			res.push_back(x);
		}
	}
	return res;
}

int main() {

	vector<vector<int> > res;
	vector<vector<int> > vec;

	int n = 0;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n; i++) {

		vector<int> v1;

		for (int j = 0; j < 2; j++) {
			cin >> num;
			v1.push_back(num);
		}
		vec.push_back(v1);
	}
	res = merge(vec);

	for (vector<vector<int>>::size_type i = 0; i < res.size(); i++){
		for (vector<int>::size_type j = 0; j < res[i].size(); j++){
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}

