#include<iostream>

using namespace std;

int main() {
	int array[100];
	int n,t = 0,m=0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int br = 0;
	int i = 0;

		while (i < n)
		{
			if (array[i] < array[i+1])
			{
				br++;
			}
		
			i++;
		}
		

	if (br+1 == n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}