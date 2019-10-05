#include <iostream>

using namespace std;

int main()
{
	const int SIZE = 30;
	int n,m;
	int arrayA[SIZE];
	int arrayB[SIZE];
	int skalar = 1;

	cout << "A{n}, n-count n=";
	cin >> n;
	
	cout << "B{m}, m-count m=";
	cin >> m;

	cout << "A:";
	for (int i = 0; i<n; i++)
	{
		cin >> arrayA[i];
	}
	

	cout << "B:";
	for (int i = 0; i<m; i++)
	{
		cin >> arrayB[i];
	}
	

	cout<< "A{";
	for (int i = 0; i<n; i++)
	{
		cout<<arrayA[i];
		if(arrayA[i]!= arrayA[n-1])
		cout << ",";
	}
	cout << "}"<<endl;

	cout << "B{";
	for (int i = 0; i<n; i++)
	{
		cout << arrayB[i];
		if (arrayB[i] != arrayB[m-1])
			cout << ",";
	}
	cout << "}" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			skalar = (arrayA[i] * arrayB[j]) / (fabs(arrayA[i]) * fabs(arrayB[j]));
		}
		cout << skalar << endl;
	}
	
	return 0;
}
