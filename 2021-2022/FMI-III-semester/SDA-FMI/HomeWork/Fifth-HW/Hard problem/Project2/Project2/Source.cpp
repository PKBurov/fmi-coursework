#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//	int maxSlidingWindow(vector<int>& nums, int k) {
//		int n = nums.size();
//
//		int res=0;
//		int left = 0, right = 0;
//		int sum = 0;
//
//		/*if (k == 1)
//			return nums;*/
//
//		for (; right < n; right++) {
//			while (right < k - 1) {
//				sum = min(sum, nums[right]);
//				right++;
//			}
//
//			sum = min(sum, nums[right]);
//			res += sum;
//
//			if (sum == nums[left]) {
//				int l = left + 1;
//				sum = nums[l];
//				while (l <= right) {
//					sum = max(sum, nums[l]);
//					l++;
//				}
//			}
//
//			left++;
//		}
//		return res;
//	}
//
//int main() {
//	vector<int> Elements;
//	
//
//	int N, K;
//	cin >> N>> K;
//
//	for (int i = 0; i < N; i++){
//		int input;
//		cin >> input;
//		Elements.push_back(input);
//	}
//	cout << maxSlidingWindow(Elements, K);
//
//}

int MinSum(int arr[], int n, int k){
	int sum = 0; 
	deque<int> Small(k);
	int i = 0;
	for (i = 0; i < k; i++){
		while ((!Small.empty()) && arr[Small.back()] >= arr[i]) {
			Small.pop_back();
		} 
		Small.push_back(i);
	}
	// Process rest of the Array elements 
	for (; i < n; i++){
		sum += arr[Small.front()];
		while (!Small.empty() && Small.front() <= i - k) {
			Small.pop_front();
		}
		while ((!Small.empty()) && arr[Small.back()] >= arr[i]) {
			Small.pop_back();
		} 
		Small.push_back(i);
	}
	// Sum of minimum and maximum element of last window 
	sum += arr[Small.front()];

	return sum;
}

int arr[(int)1e7] = { 0 };
int main(){
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	cout << MinSum(arr, N, K);
	
}