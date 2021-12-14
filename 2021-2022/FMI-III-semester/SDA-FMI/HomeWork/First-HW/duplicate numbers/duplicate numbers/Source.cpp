#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1;
		int r = nums.size();
		while (l < r) {
			int m = (r - l) / 2 + l;
			int count = 0; // len(nums <= m)
			for (int num : nums)
				if (num <= m) ++count;
			if (count <= m)
				l = m + 1;
			else
				r = m;
		}
		return l;
	}
};