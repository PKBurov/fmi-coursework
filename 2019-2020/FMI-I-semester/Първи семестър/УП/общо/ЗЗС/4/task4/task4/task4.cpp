#include <iostream>
using namespace std;

int main(){
	int array[100];
	int n,t=0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{
		

		if (array[i] == array[i + 1] - 1)
		{
			t = 1;
		}
	}
	
	if (t==1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

return 0;
}