#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Binary_High(vector<long long>& arr, long& value);
long long BinaryofBinarySearch(vector<long long>& arr, const long& newVectorSize, const long& UpperBound);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	long Elements_len = 0;
	long Ques = 0;
	long L_bound = 0;
	long R_bound = 0;
	long Result = 0;
	long AfterBineryNumber = 0;
	long BineryNumPlusOneRight = 0;
	long BigSum = 0;

	cin >> Elements_len >> Ques;

	vector<long long> Elements(Elements_len);
	vector<long long> Arr_Sum(Elements_len);

	for (long i = 0; i < Elements_len; i++){
		cin >> Elements[i];
	}
	// Sorting Array from Smallest to Biggest
	sort(Elements.begin(), Elements.end());

	long long sum = 0;
	//Taking the global sum of all values
	for (long i = 0; i < Elements_len; i++){
		sum += Elements[i];
	}
	//We place the max sum first and then we start substracting every index from the next;
	Arr_Sum[0] = sum;
	for (long i = 1; i < Elements_len; i++){
		Arr_Sum[i] = Arr_Sum[i - 1] - Elements[i - 1];
	}
	//We add this because in some cases, we substract the sums, but there isnt any number on Elements+1 index, so we add 0 to substract with 0 and we check again all of the values
	Arr_Sum[Elements_len] = 0;

	for (long i = 1; i < Ques+1; i++){
		
		cin >> L_bound >> R_bound;
		//Get number after binerynumber
		AfterBineryNumber = Binary_High(Elements,R_bound);
		//Get the number we will be substracting with and the actual size
		BineryNumPlusOneRight = AfterBineryNumber +1;
		//Result of the actual Double Binary
		BigSum = BinaryofBinarySearch(Arr_Sum, BineryNumPlusOneRight, L_bound);
		
		if (BigSum == -1) {
			Result = 0;
		}
		else {
			Result = BineryNumPlusOneRight - BigSum;
		}
		cout << Result << endl;
	}
	return 0;
}

//Binary Search to find the highest possition of the Vector
long long Binary_High(vector<long long>& arr, long& value) {
	long low = 0; long high = arr.size() - 1;
	while (low <= high) {
		long mid = (low + high) / 2;
		if (arr[mid] <= value) {
			low = mid + 1;
		}else {
			high = mid - 1;
		}
	}
	return high;
}

//Since we have a new UpperBound which we use as the size of the new Vector, we take that number and we loopthrough it substracting the from all the sums the binary_num+1 sum;
long long BinaryofBinarySearch(vector<long long>& arr_Sums, const long& newVectorSize, const long& UpperBound) {

	long long low = 0;
	long long NewVectorSize = newVectorSize;
	long long high = NewVectorSize - 1;
	long long SubstractingSum = newVectorSize;
	long long BiggestNumberSoFar = 0;
	long long NeededIndex = -1;

	//We take the left side of the arrIndex from the first binary and thats are new vector we will be working with, then we make another binary of that side of the array/vector
	while (low <= high) {

		if (low == -1 || high == -1) { break; }
		long long mid = (low + high) / 2;

		if (arr_Sums[mid] - arr_Sums[SubstractingSum] <= UpperBound && arr_Sums[mid] - arr_Sums[SubstractingSum] > BiggestNumberSoFar) {
			high = mid - 1;
			BiggestNumberSoFar = arr_Sums[mid] - arr_Sums[SubstractingSum];
			NeededIndex = mid;
		}
		else if (arr_Sums[mid] - arr_Sums[SubstractingSum] <= UpperBound && arr_Sums[mid] - arr_Sums[SubstractingSum] < BiggestNumberSoFar) {
			break;
		}
		else { low = mid + 1; }
	}
	return NeededIndex;
}