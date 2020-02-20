#include<iostream>
using namespace std;
/*Задача 2. 
а) Да се напише функция, която проверява дали дадено цяло число x е точна степен на дадено цяло число n.
*/
bool degree(int x, int n)
{
	int check = 1;
	bool flag = false;

	if (x == n)
	{
		flag = true;
	}
	else
	{
		while (check < x)
		{
			check = check * n;

			if (x == 0 || n == 0 || n == 1)
			{
				check = x + n + 1;
			}

			if (check == n)
				flag = true;
			
		}

		if (x == 1)
			flag = true;
	}

	return flag;
}
//б) Да се напише функция, която по дадени цели числа k и p (1 ≤ k,p ≤ 100) и масив от цели числа a, определя дали в a има поне k числа, които са точни степени на p.
int main()
{
	/*int n, x;
	cin >> x >> n;
	cout << degree(x, n) << endl;
	*/
	int k, p;
	cin >> k >> p;
	int a[9] = {3,9,11,27,81,243,3,9,27};
	int counter = 0;

	int check = 0;
	for (int i = 0; i < 9; i++)
	{
		check = a[i];
		if (degree(check, p))
			counter++;
	}
	if (counter >= k)
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}