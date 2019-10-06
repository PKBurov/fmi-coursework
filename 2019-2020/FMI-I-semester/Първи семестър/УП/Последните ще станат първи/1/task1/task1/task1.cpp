#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	
	int Xa, Ya, Xb, Yb, Xc, Yc;
	cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;
	double lenghtA, lenghtB, lenghtC;
	double a, b, c;
	//double S = 0;
/*
	cin >> a >> b >> c;

	лице на паралелепипед
	S = 2*(a*b + a*c + b*c);
	cout << S << endl;

	Определяне на вида на триъгълник

	if (a + b < c || a + c < b || c + b < a)
	{
		cout << " Not exist!" << endl;
	}
	else
	{

		if (a == b && b == c)
		{
			cout << "ravnostranen" << endl;
		}

		if ((a ==b && a!=c ) || (b == c && b != a) || (a == c && a != b))
		{
			cout << "ravnobedren" << endl;
		}

		if (a != b && b != c && a != c)
		{
			cout << "raznostranen" << endl;
		}
	
	}*/

	lenghtA = pow((Xb - Xa), 2) + pow((Yb - Ya), 2);
	lenghtA = sqrt(lenghtA);

	lenghtB = pow((Xb - Xc), 2) + pow((Yb - Yc), 2);
	lenghtB = sqrt(lenghtB);

	lenghtC = pow((Xa - Xc), 2) + pow((Ya - Yc), 2);
	lenghtC = sqrt(lenghtC);

	cout <<"a="<< lenghtA << endl;
	cout << "b=" << lenghtB << endl;
	cout << "c=" << lenghtC << endl;

	a = lenghtA;
	b = lenghtB;
	c = lenghtC;

	if (a == 0 || b == 0 || c == 0)
	{
		cout << "Invalid input!"<<endl;
	}
	else if(Ya==Yb && Yb==Yc && Ya == Yc) 
	{
		cout << "Invalid input!" << endl;
		
	}
	else if(a+b<=c || a+c<=b || b+c<=0)
	{
		cout << "Invalid input!" << endl;
	}
	else if(Xa == Xb && Xb == Xc && Xa == Xc)
	{
		cout << "Invalid input!" << endl;
		
	}
	else if (a + b < c || a + c < b || c + b < a)
	{
		cout << "Invalid input!" << endl;
	}
	else
	{

		if (a == b && b == c )
		{
			cout << "ravnostranen" << endl;
		}

		if ((a == b && a != c) || (b == c && b != a) || (a == c && a != b))
		{
			cout << "ravnobedren" << endl;
		}

		if (a != b && b != c && a != c)
		{
			cout << "raznostranen" << endl;
		}
	}





}