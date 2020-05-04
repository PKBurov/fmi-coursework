using namespace std;
#include<iostream>
int main()
{
	char arrA[100][100];
	int m, n;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "arrA[" << i << "][" << j << "]=";
			cin >> arrA[i][j];
		}
		
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{		
			cout << arrA[i][j]<<"   ";
		}
		cout << endl;
	}

}