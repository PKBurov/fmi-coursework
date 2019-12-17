#include<iostream>
#include<algorithm>

using namespace std;

int* multiple(int* f, int* s, int n, int m);
int main()
{
	
	int n;
	cin >> n;
	int* f;
	f = new int[n];
	for (int i = 0; i < n; i++){
		cin >> f[i];
	}

	int m;
	cin >> m;
	int* s;
	s = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	int* something = multiple(f, s, n, m);
	delete[] f;
	delete[] s;
	for (int i = 0; i < max(n,m) ; i++){
		cout << something[i]<<' ';
	}
	delete[] something;
	

	return 0;
}
int* multiple(int* f, int* s, int n, int m) {

	int* dynamic_arr, maxLenght=0;
	if (n > m) { maxLenght = n;}
	if (m > n) { maxLenght = m;}
	if (n = m) { maxLenght = n;}
	//1 2 3 4
	//4 2

	dynamic_arr = new int[maxLenght];

	int count = 0;

	if (n > m) {
		for (int j = 0; j < n; j++) {
			if (j < n) { dynamic_arr[j] = f[j] * s[j]; }
			else
				dynamic_arr[j] = f[j] * 1;
		}
	}
	else if (n == m) {
		for (int i = 0; i < n; i++) {
			dynamic_arr[i] = f[i] * s[i];
		}
	}
	else {
		for (int j = 0; j < m; j++) {
			count++;
			if (count > n) {
				for (int z = j; z < m; z++) {
					dynamic_arr[z] = s[z];
				}
			}else{
				dynamic_arr[j] = f[j] * s[j];
			}
			
		}
	}
	
	return dynamic_arr;
}
	