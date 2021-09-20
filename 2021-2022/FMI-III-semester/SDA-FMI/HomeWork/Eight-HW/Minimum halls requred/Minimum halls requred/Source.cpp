#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Point {
	long long int x, y;
	bool operator<(Point p) {return x < p.x || (x == p.x && y < p.y);}
};

long long int Result(Point O, Point A, Point B) {
	return (A.x - O.x) * (B.y - O.y)- (A.y - O.y) * (B.x - O.x);
}

vector<Point> Hull(vector<Point> Apoint) {
	int n = Apoint.size(), k = 0;
	if (n <= 3){ return Apoint; }

	vector<Point> answer(2 * n);
	sort(Apoint.begin(), Apoint.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && Result(answer[k - 2], answer[k - 1], Apoint[i]) <= 0) {k--;}
		answer[k++] = Apoint[i];
	}
	for (int i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= t && Result(answer[k - 2], answer[k - 1], Apoint[i - 1]) <= 0) { k--; }
		answer[k++] = Apoint[i - 1];
	}
	answer.resize(k - 1);

	return answer;
}
double Distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y));
}

double Perimeter(vector<Point> result)
{
	double perimeter = 0.0;
	for (int i = 0; i < result.size() - 1; i++) {
		perimeter += Distance(result[i], result[i + 1]);
	}
	perimeter += Distance(result[0], result[result.size() - 1]);

	return perimeter;
}

int main()
{
	vector<Point> points;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		Point newpoint;
		cin >> newpoint.x;
		int x = newpoint.x;
		cin >> newpoint.y;
		int y = newpoint.y;

		points.push_back({ x,y });
	}
	vector<Point> ans = Hull(points);
	printf("%.2f", Perimeter(ans));

	return 0;
}