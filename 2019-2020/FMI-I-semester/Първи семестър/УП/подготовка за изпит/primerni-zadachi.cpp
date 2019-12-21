// primerni zadachi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int gcd(int x, int y);
double power(double x, int n);
int square(int n);
double fun(int x);
int factoriel(int x);
void str();
int matrixSum(int a[4][4]);
void binary(int &a);
int SumOfSquare(int a);
bool truth(int a);
int rev(int a);
int summ(int a);
int matrixk(int a[3][3]);
void srGeo(int a[5], double &d);
float matrix3(float a[3][3]);

//nod
int gcd(int x, int y) 
{
	while (x != y)
		if (x > y)
			x = x - y;
		else
			y = y - x;
	return x;
}
//pow
double power(double x, int n) {
	if (n == 1) return 1;
	else if (n < 0) return 1.0 / pow(x, -n);
	else if (n > 1) return x * pow(x, n - 1);

} 
//square
int square(int n) {
	if (n == 1) return 1;
	else return ((2 * n - 1) + square(n - 1));
	//return (n == 1) ? 1 : 2 * n - 1 + square(n - 1);
}

//sumata
double fun(int x)
{
	double sum = 0;
	for (int i = 0; i <= 5; i++)
		sum += pow(-1, i)*(pow(x, 2 * i + 1) / factoriel(2 * i + 1));
	return sum;
}

int factoriel(int x)
{
	if (x == 0 || x == 1) return 1;
	else return x*factoriel(x - 1);
}

//obhojdane ot n-1

//palindrom
void str() {
	char a[10], b[10];
	cout << "a= ";
	cin >> a;
	int n = strlen(a);
	for (int i = n - 1; i >= 0; i--)
		b[n - i - 1] = a[i];
	b[n] = '\0';
	if (!strcmp(a, b))
		cout << "palindrome" << endl;
	else cout << "not palindrome";
}

//suma na matrica
int matrixSum(int a[4][4])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j && j != 4 - i - 1)
				sum += a[i][j];
	return sum;
}

void binary(int &a)
{
	int r, i = 1, b = 0;
	while (a != 0)
	{
		r = a % 2;
		a /= 2;
		b += r*i;
		i *= 10;
	}
	a = b;
}

//suma ot kvadrati na chislo
int SumOfSquare(int a) 
{
	int b, sum = 0;
	while (a != 0) {
		b = a % 10;
		a /= 10;
		sum += pow(b, 2);
	}
	return sum;
}
//prowerka za prosto 4islo
bool truth(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0)
			return false;
	return  true;
}

//rivarsvane na 4islo
int rev(int a)
{
	int num = 0;
	while (a != 0)
	{
		num *= 10;
		num += a % 10;
		a /= 10;
	}
	return num;
}

//matrica sas sumite
int matrixk(int a[3][3])
{
	int counter = 1;
	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
		{
			a[i][j] = summ(counter);
			counter++;
		}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (j < 3 - 1 - i)
				sum += a[i][j];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return sum;
}

int summ(int a) 
{
	int sum = 0;
	for (int i = 1; i <= 3; i++)
		sum += pow(i, a);
	return sum;
}

//Sredno Geometri4no
void srGeo(int a[5], double &d)
{
	double b = 1.0;
	for (int i = 0; i < 5; i++)
		b *= a[i];
	double c = pow(b, 0.2);
	d = c;
}

float matrix3() 
{
	float a[3][3];
	int br = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				a[i][j] = sin(factoriel(br));
			else
				a[i][j] = cos(factoriel(br));
			br++;
		}
	float sum = 0;
	for (int i = 0; i < 3; i++)
		sum += a[2][i];
	return sum;
}

//matrica ot nizove tarsene na duma
int searchs(string a[100][100], int n, string s)
{
	int br = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			if (j > n - 1 - i && a[i][j] == s)
				br++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return br;
}

int main()
{
	/*int a;
	cin >> a;
	cout << fun(a) << endl;*/
	
	/*int arr[4][4] =
	{ {1,2,9,12},
	{5,6,8,4},
	{10,15,13,17},
	{20,18,16,777} };
	for (int k = 0; k < 4; k++)
		for (int l = 0; l < 4; l++)
			cin >> arr[k][l];
	int c = matrixSum(arr);
	binary(c);
	cout << c;*/

	/*int a = 546810781;
	a = SumOfSquare(a);
	cout << a << " " << truth(a) << " " << rev(a) << "\n";*/
	/*int a[3][3];
	cout << matrixk(a);*/
	/*int a[] = { 4,6,8,5,2 };
	double b = 2.0;
	srGeo(a, b);
	cout << b;*/
	//cout << matrix3() << endl;
	/*string a[100][100], s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cin >> s;
	cout << searchs(a, n, s);*/
	int n;
	cin >> n;
	int i;
	int k;
	for (k = n - 1; k >= 0; k--) {
		for (i = k; i <= n - 1; i++) {
			cout << "(" << i << "," << i - k << ")" << endl;
		}
	}
	for (k = -1; k >= 1 - n; k--) {
		for (i = 0; i <= n + k - 1; i++) {
			cout << "(" << i << "," << i - k << ")" << endl;
		}
	}
	system("pause");
    return 0;
}