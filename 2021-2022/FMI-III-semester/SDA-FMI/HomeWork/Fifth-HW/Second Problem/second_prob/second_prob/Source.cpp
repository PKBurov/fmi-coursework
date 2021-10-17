#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

//int MinDaysNeeded(vector<int>& nums, int s) {
//	if (nums.empty()) {
//		return 0;
//	}
//	if (accumulate(nums.begin(), nums.end(), 0) < s) {
//		return 0;
//	}
//	int ret = nums.size(), b = 0, total = nums[0];
//	for (int i = 0; i < nums.size() && b < nums.size(); i++) {
//		while (total < s && b < nums.size() - 1) {
//			++b;
//			total += nums[b];
//		}
//		if (total >= s) {
//			ret = std::min(ret, b - i + 1);
//		}
//		total -= nums[i];
//		if (i == b) {
//			++b;
//		}
//	}
//	return ret;
//}

int MinDaysRequired(int s, vector<int>& nums) {

	int ans = INT_MAX, curr = 0;
	int l = 0;
	int r = 0;
	while (r <= nums.size()) {
		if (curr >= s) {
			ans = min(ans, r - l);
			curr -= nums[l];
			++l;
		}
		else {
			if (r < nums.size()) {
				curr += nums[r];
			}
			++r;
		}

	}
	return ans == INT_MAX ? -1 : ans;
}

int main() {
	int N, K;
	vector<int>Elements;
	cin >> N >> K;
	for (int i = 0; i < N; i++){
		int input;
		cin >> input;
		Elements.push_back(input);
	}
	cout << MinDaysRequired(K,Elements);

	return 0;
}
