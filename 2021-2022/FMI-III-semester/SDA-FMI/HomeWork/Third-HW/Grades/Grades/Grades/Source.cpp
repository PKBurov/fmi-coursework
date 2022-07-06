#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int x_indx(vector<long>& arrX, int x)
{
	int low = 0, high = arrX.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arrX[mid] >= x) {
			high = mid - 1;
		}else {
			low = mid + 1;
		}
	}
	return low;
}
int y_indx(vector<long>& arrY,int y){
	int low = 0, high = arrY.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arrY[mid] <= y)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high;
}

int main() {
	long SizeNotes, Intervals;
	cin >> SizeNotes >> Intervals;

	Intervals = Intervals * 2;
	vector<long>intervals(Intervals);
	vector<long>notes(SizeNotes);

	for (long i = 0; i < SizeNotes; i++) {
		cin >> notes[i];
	}
	sort(notes.begin(), notes.begin() + SizeNotes);

	for (long i = 0; i < Intervals; i++) {
		cin >> intervals[i];
	}

	for (long i = 0; i < Intervals; i++) {
		long ress = 0;
		if (intervals[i]>intervals[i+1]){
			ress = 0;
		}else{
			ress = y_indx(notes, intervals[i + 1]) - x_indx(notes, intervals[i]) + 1;
		}
		cout << ress << endl;
		i++;
	}
}
	
