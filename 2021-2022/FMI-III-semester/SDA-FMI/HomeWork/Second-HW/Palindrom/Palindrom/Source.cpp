#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//int isEven(int num) {
//	if (num%2==0){
//		num = 1;
//	}else{
//		num = 0;
//	}
//	return num;
//}
//int countOdd(string a) {
//	int c_arr[256] = { 0 };
//	int i, count = 0;
//
//	for (i = 0; a[i] != '\0'; i++) {
//		c_arr[a[i]]++;
//	}for (i = 0; i < 256; i++) {
//		if (c_arr[i] == 1) { count++; }
//	}
//	return count;
//}
 bool Palindrom(string str){

	int count[256] = { 0 };
	for (int i = 0; str[i]; i++)
		count[str[i]]++;

	int odd = 0;
	for (int i = 0; i < 256; i++){
		if (count[i] & 1){
			odd++;
		}
		if (odd > 1) {
			return false;
		}
	}
	return true;
}
int main() {

	int ArrSize;

	vector<string> collection;
	string word;
	cout << "Amount of strings:";
	cin >> ArrSize;

	for (int i = 0; i < ArrSize; ++i) {
			std::cin >> word;
			collection.push_back(word);
	}

	for (auto& s : collection) {
		if (Palindrom(s)==true){
			cout << "TRUE"<<endl;
		}else { cout<<"FALSE"<<endl; }
	}

























	//for (int i = 0; i < ArrSize; ++i) {
	//	std::cin >> word;
	//	collection.push_back(word);
	//}
	//for (auto& word : collection) {

	//	if (countOdd(word) >= 1 && isEven(word.size()) == 1) {
	//		Palindrom = false;
	//	}
	//	else if (countOdd(word) == 1 && isEven(word.size()) == 0) {
	//		Palindrom = true;
	//	}
	//	if (Palindrom) {
	//		cout << "TRUE" << endl;
	//	}
	//	else {
	//		cout << "FALSE" << endl;
	//	}
	//	Palindrom = true;
	//}
	//return 0;
}
