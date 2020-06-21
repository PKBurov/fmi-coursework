#include <iostream>
using namespace std;

int main()
{
	/*
 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
 1 2 3 4 5 6
 1 2 3 4 5 6 7
 */
	int i = 1;
	for (int index = 0; index <= 7; index++)
	{
		if (index != 0)
		{
			for (int t = 0; t < index; t++)
			{
				cout << i + t << " ";
			}
			cout << endl;
		}
	}
	

return 0;
}