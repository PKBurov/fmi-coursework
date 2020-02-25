// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
# include <cmath>


using namespace std;

short int pointRectCircle(double x, double y, double centurX, double centurY, double r)
{
	if (pow((x - centurX), 2) + pow((y - centurY), 2) <= pow(r, 2))
		return 1;
	else
		return 0;
}


short int pointRectCollision(double x, double y, double LBottomX, double LBottomY, double width, double height)
{
	if ((x < (LBottomX + width)) && (x > LBottomX) && (y < (LBottomY + height)) && (y > LBottomY))
		return 1;
	else
	{
		if ((x > (LBottomX + width)) || (x < LBottomX) || (y > (LBottomY + height)) || (y < LBottomY))
		return 0;
	}
		
		
	
}

int main()
{
	double x;
	cout << "x=";
	cin >> x;

	double y;
	cout << "y=" ;
	cin >> y;

	double LBottomX;
	cout << "LBottomX=" ;
	cin >> LBottomX;

	double LBottomY;
	cout << "LBottomY=" ;
	cin >> LBottomY;

	double width;
	cout << "width=" ;
	cin >> width;

	double height;
	cout << "height=" ;
	cin >> height;

	cout << pointRectCollision(x, y, LBottomX, LBottomY, width, height) << endl;

	double centurX;
	cout << "centurX=";
	cin >> centurX;

	
	double centurY;
	cout << "centurY=";
	cin >> centurY;

	double r;
	cout << "r=";
	cin >> r;

	
	cout << pointRectCircle(x, y, centurX, centurY, r) << endl;
	
    return 0;
}

