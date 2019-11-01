#include<iostream>
using namespace std;

// This pair is used to store the X and Y coordinates of a point respectively 
#define pdd pair<double, double> 
// Function used to display X and Y coordinates of a point 
void displayPoint(pdd P)
{
	cout << "(" << P.first << ", " << P.second
		<< ")" << endl;
}
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D) {
	// Line AB represented as a1x + b1y = c1 
	double a1 = B.second - A.second;
	double b1 = A.first - B.first;
	double c1 = a1 * (A.first) + b1 * (A.second);

	// Line CD represented as a2x + b2y = c2 
	double a2 = D.second - C.second;
	double b2 = C.first - D.first;
	double c2 = a2 * (C.first) + b2 * (C.second);

	double determinant = a1 * b2 - a2 * b1;
	if (determinant == 0) {
		// The lines are parallel. This is simplified 
		// by returning a pair of FLT_MAX 
		return make_pair(FLT_MAX, FLT_MAX);
	}
	else {
		double x = (b2 * c1 - b1 * c2) / determinant;
		double y = (a1 * c2 - a2 * c1) / determinant;
		return make_pair(x, y);
	}
}