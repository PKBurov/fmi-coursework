//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <queue>
//using namespace std;
//
//
//vector<int> CollidingTrucks(vector<int>& arr) {
//
//	stack<int> TrucksLeft;
//
//	for (int i = 0; i < arr.size(); i++){
//		//Towa go dobavqme, zashtoto nikoga naqma da se udarqt
//		if (TrucksLeft.empty() || arr[i]>0) {
//			TrucksLeft.push(arr[i]);
//		}else {
//			while (true) {
//				int peek = TrucksLeft.top();
//					if (peek < 0){
//						TrucksLeft.push(arr[i]); //[-5,-4] -4
//						break;
//					}
//					else if (peek == -arr[i]) {
//						TrucksLeft.pop(); //[-5,-4,4] -4 //pop 4 and -4
//						break;
//					}
//					else if (peek > -arr[i]) {
//						break;				//[-5,-4,5] -4// nishto izhvurlen e
//					}
//					else {
//						TrucksLeft.pop();
//						if (TrucksLeft.empty()){
//							TrucksLeft.push(arr[i]);    //[-5,4,3,2,1] -4 mahame 1 i posle pak while(true) proverka i mahame prez drugoto vreme	
//							break;
//						}
//					}
//			}
//		}
//	}
//	int size = TrucksLeft.size();
//	vector<int> res(size);
//	while (!TrucksLeft.empty()) {
//		res[--size] = TrucksLeft.top();
//		TrucksLeft.pop();
//	}
//	return res;
//}
//
//
//int main() {
//	int numTrucks,input;
//	vector<int> Trucks;
//	cin >> numTrucks;
//	for (int i = 0; i < numTrucks; i++){
//		cin >> input;
//		Trucks.push_back(input);
//	}
//	vector<int> res = CollidingTrucks(Trucks);
//	if (res.size() == 0){
//		cout << "\n";
//	}else{
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i] << " ";
//		}
//	}
//	return 0;
//}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int MinDaysRequired(int s, vector<int>& nums) {

	int Result = INT_MAX;
	int left = 0;
	int val_sum = 0;

	for (int i = 0; i < nums.size(); i++){
		val_sum += nums[i];

		//Kogato stignem do po golqma suma ot S s=7 [2,3,1,2,   4,3] otg = 2 tuk znaem, che ot 0 do 4 e >= 8 koeto e >7 ==> 
		while (val_sum >= s) {
			Result = min(Result, i + 1 - left); // i = 3 // 4-0 = 4
			val_sum -= nums[left]; //mahame ot nums left i posle left ++ shte stane 3+1+2 koeto chupi while i posle otivame v val_sum i dobavqme ot dqsno i pak
			left++;
		}
	}

	return (Result != INT_MAX) ? Result : -1;
}

int main() {
	int N, K;
	vector<int>Elements;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		Elements.push_back(input);
	}
	cout << MinDaysRequired(K, Elements);

	return 0;
}
