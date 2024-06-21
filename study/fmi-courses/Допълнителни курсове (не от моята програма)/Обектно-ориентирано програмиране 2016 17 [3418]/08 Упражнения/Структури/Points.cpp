#include <iostream>
#include <iomanip>

/*
	Да се дефинира функция, която намира разстоянието между
	две точки в равнината. Като се използва тази функция, да се
	напише програма, която въвежда координатите на n точки в равнината
	(2 <= n <= 100), намира и извежда най-голямото разстояние между тях.

	Да се дефинира подходяща структура, която представя точка в равнината
	с декартови координати.
*/

// декларация на структура Point, представяща
// точка в равнината с декартови координати
struct Point
{
	double x, y;
};


// прочитане на координатите на точка
void createPoint(Point& point)
{
	std::cout << "Please, enter x: ";
	std::cin >> point.x;

	std::cout << "Please, enter y: ";
	std::cin >> point.y;
}

// извеждане на координатите на точка в равнината
void printPoint(const Point& point)
{
	std::cout << "(" << point.x << ", " << point.y << ")\n";
}

// намиране на разстоянието между две точки
double segmentDistance(const Point& p1, const Point& p2)
{
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

// въвеждане на масив от точки
void readPoints(Point* arr, size_t n)
{
	Point* end = arr + n;
	for(Point* curr = arr; curr < end; ++curr)
	{
		createPoint(*curr);
	}
}

// намиране на най-голямото разстояние между точките
void printMaxDistance(Point* arr, size_t n)
{
	Point* end = arr + n - 1;

	double maxDist = 0;
	Point *mdFirst = NULL, *mdSecond = NULL;

	for(Point* first = arr; first < end; ++first)
	{
		for(Point* second = first + 1; second <= end; ++second)
		{
			double currDistance = segmentDistance(*first, *second);
			if(maxDist < currDistance)
			{
				maxDist = currDistance;
				mdFirst = first;
				mdSecond = second;
			}
		}
	}

	std::cout << std::setiosflags(std::ios::fixed | std::ios::showpoint) << std::setprecision(2);
	std::cout << maxDist << std::endl;
	
	printPoint(*mdFirst);
	printPoint(*mdSecond);
}

int main()
{
	// деклариране на колекцията от точки
	Point points[5];

	readPoints(points, 5);
	printMaxDistance(points, 5);

	Point p = { 3, 4 };
	
	Point* pp = &p;
	printPoint(*pp);

	pp->x = 7;
	printPoint(*pp);

	(*pp).x = 5;
	printPoint(*pp);

	return 0;
}