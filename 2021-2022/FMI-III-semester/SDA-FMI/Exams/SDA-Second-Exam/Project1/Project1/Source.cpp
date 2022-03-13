
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int n, arr[3000000], shift, q;
//
//int bs(int x) {
//	int l = 0, r = n - 1;
//	while (l<r){
//		int mid = l + (r - l) / 2;
//		if (arr[mid]==x){
//			return mid;
//		}
//		if(arr[mid]<x){
//			l = mid + l;
//		}
//		else
//		{
//			r = mid;
//		}
//	}
//	return -1;
//}

//int main() {
//	cin >> n;
//	cin >> arr[0];
//	for (int i = 1; i < n; i++){
//		cin >> arr[i];
//		if (arr[i] < arr[i - 1]) shift = i;
//	}
//	cin >> q;
//	int a, ans;
//	sort(arr, arr + n);
//	for (int i = 0; i < q; i++){
//		cin >> a;
//		ans = bs(a);
//		if (ans==-1)
//		{
//			cout << -1 << endl;
//		}
//		else
//		{
//			cout << (ans + shift) % n << endl;
//		}
//	}
//
//	return 0;
//}
int arr[3000000];
int arr_elements;
int ques;
int shift;
int lowestNumberIndex;

int binary(int x) {
	int l = 0, r = arr_elements - 1;
	while (l<r){
		int mid = l + (r - l) / 2;
		if (arr[mid]==x){
			return mid;
		}if (arr[mid]<x){
			l = mid + 1;
		}else {
			r = mid;
		}

	}
	return -1;
}
int Minloc(int* arr, int size) {
	int location = 0;
	for (int c = 1; c < size; c++)
		if (arr[c] < arr[location])
			location = c;

	return location;
}

int main() {
	
	cin >> arr_elements;
	for (int i = 0; i < arr_elements; i++){
		cin >> arr[i];
	}
	lowestNumberIndex = Minloc(arr, arr_elements);
	sort(arr, arr+arr_elements);

	cin >> ques;
	for (int i = 0; i < ques; i++){
		int answer, a;
		cin >> a;
		answer = binary(a);
		if (answer==-1){
			cout << -1 << endl;
		}
		else {
			cout << (answer + lowestNumberIndex) % arr_elements << endl;
		}
	}
	return 0;
}

