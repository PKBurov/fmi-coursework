#include<iostream>
#include<cmath>

using namespace std;


int main() {

	//удвоено нечетно число, след намиране на нечетното число го умножаваме по 2

	int array[20];
	int n, proizvedenie = 1,sum=0,m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{

		if (array[i] <0)
		{
			m = abs(array[i]);
			proizvedenie = proizvedenie* m;
		}

		if (array[i] >0)
		{
			sum += array[i];
		}
	}
	cout <<"proizvedenie="<< proizvedenie << endl;
	cout <<"sum=" <<sum << endl;
	return 0;
}