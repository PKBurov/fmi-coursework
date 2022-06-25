#include<iostream>
using namespace std;


long FoodEten(long NumberOfcows, long Intervals, long Value) {
	if (Intervals == 1) {
		return Value;
	}
	long  k = NumberOfcows / 3;
	if (Intervals <= k) {
		return FoodEten(NumberOfcows, k, Value + 1);
	}else if (NumberOfcows <= k * 2) {
		return Value;
	}
	else {
		return FoodEten(NumberOfcows - k * 2, k, Value + 1);
	}
}
int main()
{
	long long degree, num_cows, n_cows;
	cin >> degree >> num_cows;

	long long k = pow(3, degree);

	for (int i = 1; i < num_cows+1; i++) {
		cin >> n_cows;
		cout << FoodEten(n_cows, k, 1) <<endl;
	}
}

/*
#include<stdio.h>
#include<math.h>



long long FoodEten(long long NumberOfcows, long Intervals, long Value) {
	if (Intervals == 1) {
		return Value;
	}
	long  k = NumberOfcows / 3;
	if (Intervals <= k) {
		return FoodEten(NumberOfcows, k, Value + 1);
	}else if (NumberOfcows <= k * 2) {
		return Value;
	}
	else {
		return FoodEten(NumberOfcows - k * 2, k, Value + 1);
	}
}
int main()
{
	long degree, num_cows, n_cows;
	scanf("%ld", &degree);
	scanf("%ld", &num_cows);

	long k = pow(3, degree);

	for (int i = 1; i < num_cows+1; i++) {
		scanf("%ld", &n_cows);
		printf("%ld",FoodEten(n_cows, k, 1));
	}
}

*/