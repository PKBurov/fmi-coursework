#include<iostream>
using namespace std;
//long long gcd(long long a, long long b);
//void reduce(long long a, long long b);
//long long Abs(long long a);
//
//
//int main()
//{
//	long long  a, b;
//	cin >> a; cin >> b;
//	long long gcd(a,b);
//	return 0;
//}
//long long Abs(long long a)
//{
//	return a < 0 ? -a : a;
//}
//long long gcd(long long a, long long b)
//{
//	a = Abs(a);
//	b = Abs(b);
//	while (a!=0 && b!=0)
//	{
//		if (a > b) { a %= b; }
//		else
//		{
//			b %= a;
//		}
//	}
//	return a+b;
//}
//void reduce(long long a, long long b)
//{
//	if (b==0)
//	{
//		cout << "division by zero\n";
//		return;
//	}
//	if (a == 0) b = 1;
//	if (b < 0)
//	{
//		a = -a;
//		b = -b;
//	}
//	long long p = gcd(a, b);
//	a /= p;
//	b /= p;
//	cout << a;
//	if (b != 1) cout << '/' << b;
//	if (a != 1) cout << '/' << a;
//
//}


int cnt(int n, int d)
{
	int c = 0;
	c++;
	n /= d;
}
int cofzeros(int n)
{
	for (int i = 0; i < n; i++)
	{
		int t, count2 = 0, count5 = 0;
		cin >> t;
		if (t == 0)return 1;
		count2 += cnt(t, 2);
		count5 += cnt(t, 5);
	}
	return Min(count2, count5);
}
int main()
{
	int a=0, b=0, c=0, d=0, e=0, num= 0,k,count=0;
	cin >> a; cin >> b; cin >> c; cin >> d;cin>> e;
	num = a * b * c * d * e;

	while (num != 0)
	{
		k = num % 10;

		if (k == 0)
			count++;


		num = num / 10;

	}
	cout << "\n" << count;


	return 0;
}
