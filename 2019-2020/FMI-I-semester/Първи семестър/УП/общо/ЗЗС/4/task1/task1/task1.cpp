#include <iostream>

using namespace std;

int main()
{

	int array[50];
	int n, min=50;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		if (array[i] < min)
			min = array[i];
	}
	cout << min << endl;
	return 0;
}