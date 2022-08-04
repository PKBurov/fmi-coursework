#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


int main() {
	int printers;
	long long sheets, result;
	cin >> sheets >> printers;
	
	long long *machines = new long long[printers];
	for (int i = 0; i < printers; i++) {
		cin >> machines[i];
	}

	long long low = 1;
	long long high = 1e18;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long done = 0;
		for (int i = 0; i < printers; i++) {
			done += mid / machines[i];
			if (done >= sheets)
				break;
		}
		if (done >= sheets) {
			high = mid - 1;
			result = mid;
		}
		else
			low = mid + 1;
	}
	delete[]machines;
	cout << result;
	return 0;
}

//using namespace std;
//
//vector<string> split_string(string);
//long compute_time_rec(vector<long> machines, long production_goal, long min_days, long max_days);
//
//// Hackerrank minimum time required Solution
//// Runs in O( nlog(m) ) where n is number of machines
//// and m is the production goal.
//// bounded by the implementation of sort
//// ======== SOLUTION ========
//
//long minTime(vector<long> machines, long goal) {
//	sort(machines.begin(), machines.end());
//	return compute_time_rec(machines, goal, 1, machines.back() * goal);
//}
//
//long compute_time_rec(vector<long> machines, long production_goal, long min_days, long max_days) {
//	if (machines.size() == 1)
//		return max_days;
//
//	if (min_days == max_days)
//		return min_days;
//
//	long mid = (min_days + max_days) / 2;
//	long production = 0;
//
//	for (int i = 0; i < machines.size(); i++)
//		production += floor(mid / machines[i]);
//
//	if (production >= production_goal)
//		return compute_time_rec(machines, production_goal, min_days, mid);
//	else
//		return compute_time_rec(machines, production_goal, mid + 1, max_days);
//}
//
//
//
//
//// ======== BONUS  ========
//// Fixed-stack iterative solution
//long compute_time_iter(vector<long> machines, long production_goal, long min_days, long max_days) {
//	if (machines.size() == 1) return max_days;
//
//	long mid;
//	long production;
//
//	while (min_days != max_days) {
//
//		mid = (min_days + max_days) / 2;
//		production = 0;
//
//		for (int i = 0; i < machines.size(); i++)
//			production += floor(mid / machines[i]);
//
//		if (production >= production_goal)
//			max_days = mid;
//		else
//			min_days = mid + 1;
//	}
//
//	return min_days;
//}
//
//// ======== I/O handling =========
//int main()
//{
//	int n;
//	long goal;
//
//	cin >> n;
//	cin >> goal;
//
//	vector<long> machines(n);
//
//	for (int i = 0; i < n; i++)
//		cin >> machines[i];
//
//	long result = minTime(machines, goal);
//
//	cout << result << endl;
//
//	return 0;
//}
//
//
////≈то това е втора задача, разбери € утре и € напиши <3 