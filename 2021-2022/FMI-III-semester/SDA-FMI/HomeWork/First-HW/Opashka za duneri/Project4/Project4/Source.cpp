#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//vector<string> LineCheating(vector<string>& A) {
//
//	int n = A.size();
//	int position = 0;
//	for (int i = 0; i < n; i++) {
//		if (A[i]=='-') {
//			position ++;
//		}
//		if (position == 3){
//			A.push_back('M');
//		}
//	}
//	for (int i = 0; i < n; i++)
//		s.push_back(A[i]);
//
//	return s;
//}

int main() {

	int len;
	string str;

	cin >> len;
	cin >> str;
	int max = 0, current = 0, start = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] == '-') {
			++start;
		}else { break;}
	} for (int i = 0; i < len; i++) {
		if (str[i] == '-') {
			++current;
		} if (str[i] == 'x') {
			if (current > max) {
				max = current;
			}
			current = 0;
		}
	}if (start > current) {
		current = start;
	}if (current >= max / 2) {
		cout << current - 1;
	}else {
		if (max == 0) {
			cout << -1;
		}else {
			cout << ((max - 1) / 2);
		}
	}
	return 0;
}
/*
	for (int i = 0; i < len; i++) {
		if (str[i]=='-'){
			line_counter++;
			if (str[i+1]=='x'||str[i+1]== NULL){
				x_count++;
				if (line_counter >= biggest){
					biggest = line_counter;
					line_counter = 0;
				}
			}
		}
		if (str[i] == 'x') {
			x_count++;
		}
	}
	if (x_count==len){
		std::cout<< -1;
	}else if (biggest <= 2) {
		std::cout << 0;
	}else{
		std::cout<<biggest / 2;
	}
	
	return 0;*/
	//x---xx--x / xxx--xx--x /- - - - - - - x - - - - - x x

	/*
	int len;
	cin>>len;
	char* arr= new char[length];
	cin>>len;
	int max=0,current=0,start=0;

	for(int i=0; i<length;i++){
		if(arr[i]=='-'){
			++start;
		}else{
			break;
		}}
 for(int i=0; i<length;i++){
		if(arr[i]=='-'){
			++current;
		}
		if(arr[i]=='x'){
			if(current>max){
				max = current;
			}
			current=0;
		}
	}
	if(begining>current){
		current=start;
		}
	  if(current>=max/2){
			   cout<<current-1;
	}else{
	if(max==0){
				cout<<-1;
	}else{
	   cout<<((max-1)/2);
	}}
	delete[]arr;
	return 0;

}
	*/
}