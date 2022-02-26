#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Insertion Sort....

void medianafunc(vector<double>& vector) {
	double mediana;
	int counter = 0;
	sort(vector.begin(), vector.end());
	int n = 0;
	for (int i = 0; i <= n; i++){
		counter++;
		if (i==0){
			cout << vector[i]<< endl;
		}else if (counter & 1) {
			if (n/2==0){
				cout << vector[0] << endl;
			}
			cout<< vector[n / 2]<<endl;
		}else {
			 mediana = vector[(counter/2)] + vector[((counter/2)-1)];
			 cout<< mediana / 2 << endl;
		}
		 if (n < vector.size()-1){
			 ++n;
		 }
		 
	}
}

int main() {
	
	int size=0;
	int counter = 0;
	cin >> size;

	vector<double> mediana(size);

	for (double i = 0; i < mediana.size(); i++){
		cin >> mediana[i];
	}
	medianafunc(mediana);

	return 0;
}
