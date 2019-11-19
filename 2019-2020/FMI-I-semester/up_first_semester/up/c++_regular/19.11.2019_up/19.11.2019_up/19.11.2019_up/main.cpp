#include<iostream>
using namespace std;
void nm_obsh_delitel(int num1, int num2);
int main()
{
	int num1 = 0, num2 = 0;
	cout << "[2,20]" << endl;
	cin >> num1 >> num2;

		nm_obsh_delitel(num1, num2);
	
	
	return 0;
}
void nm_obsh_delitel(int num1, int num2) {

	int l_v = num1;
	int temp = num2;
	int l_dom = 0;

	while (l_v != temp){
		if (l_v > temp)
			l_v -= temp;
		else
			temp -= l_v;
	}
	l_dom = (num1 * num2) / l_v;
	cout << "Lowest denominiter = " << l_dom;
}