#include<iostream>

using namespace std;

int main(){

	

	int array[50];
	int n,m,sum=0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}


	for (int i = 0; i < n; i++)
	{
		n = array[i] % 2;
		if (n==0)
		{
			m=array[i] / 2;
			if (m % 2 != 0)
				sum += m;
		}

	}
	
	cout << sum << endl;
	return 0;
}