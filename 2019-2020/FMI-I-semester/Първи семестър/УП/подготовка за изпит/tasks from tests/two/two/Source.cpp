#include<iostream>
#include<cmath>

using namespace std;
/*
Дадени са дробните числа x и y, задаващи координати на точка в равнината и дробното число a > 0,  
Да се напише израз, който е истина точно тогава, когато точката попада в рамките на къщичката на схемата долу (вкл. и контурите).
*/
double Distance(double xA, double yA, double xB, double yB)
{
	double distance = fabs(xA - xB) + fabs(yA - yB);
	return sqrt(distance);
}

double Surface(double a, double b, double c)
{
	double halfPerimeter = (a + b + c) / 2;
	double Surface;

	Surface = halfPerimeter*(halfPerimeter - a)*(halfPerimeter - b)*(halfPerimeter - c);
	return sqrt(Surface);
}

double Surface(double a, double b, double c)
{
	double halfPerimeter = (a + b + c) / 2;
	double Surface;

	Surface = halfPerimeter*(halfPerimeter - a)*(halfPerimeter - b)*(halfPerimeter - c);
	return sqrt(Surface);
}

int DifferentSurfaces(double x, double y)
{
	double a = 0, b = 0, c = 0;
	a = Distance(x, y, 5, 10);
	b = Distance(x, y, 5, 5);
	c = Distance(x, y, -5, 5);
	double SurfaceOne = Surface(a,b,c);



}

int main()
{
	double x, y;
	double a;
	cin >> x >> y >> a;

	bool checkSquare, checktriangle;
	checkSquare = fabs(x) <= a && fabs(y) <= a;
	
	checktriangle = check(x, y);
		cout << checkSquare;
		cout << checktriangle;
	return 0;
}