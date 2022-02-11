#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

	//За сортировката
	bool static sorter(vector<int> & v1, vector<int> & v2) {
		if (v1[0] == v2[0]) {
			return v1[1] > v2[1];
		}
		return v1[0] < v2[0];
	}

	int whotwotrust(vector<vector<int>> & intervals) {
		int n = intervals.size();
		int removed = 0, curr = 0;
		sort(intervals.begin(), intervals.end(), sorter);
		for (int i = 0; i < n - 1; i++) {
			//Тъй като сме сортирали по първия, вече гледаме само втория
			if (intervals[curr][1] >= intervals[i + 1][1]) {
				removed++;
			}
			else {
				curr = i + 1;
			}
		}
		return removed;
	}

int main() {

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
	cout << whotwotrust(vec) << endl << endl;
}
