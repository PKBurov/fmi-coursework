#include <iostream>
#include <math.h>

using namespace std;

struct Point {
	double x;
	double y;
};

double findPath(Point& point1, Point& point2) {
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

double calculateTime(double& path, double& speed) {
	return path / speed;
}

double findBestTime(Point& currentMiddlePoint, Point& necromancer, Point& crewmate, double& speedTop, double& speedBot) {

	double pathCrewmate = findPath(crewmate, currentMiddlePoint);
	double pathNecromancer = findPath(necromancer, currentMiddlePoint);

	double bestTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);
	double newTime = bestTime;

	double currentDotX = currentMiddlePoint.x;
	Point newMiddlePoint = currentMiddlePoint;

	double diffrence = sqrt(currentMiddlePoint.x);

	if (currentDotX > 0)
		diffrence *= -1;

	while (bestTime <= newTime && ((diffrence < 0 && currentDotX > 0) || (diffrence > 0 && currentDotX < 0))) {
		newMiddlePoint.x += diffrence;

		pathCrewmate = findPath(crewmate, newMiddlePoint);
		pathNecromancer = findPath(necromancer, newMiddlePoint);

		newTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);

		if (newTime > bestTime) {

			for (double i = currentDotX; i >= newMiddlePoint.x; i -= 0.00001)
			{
				Point tempPoint;
				tempPoint.y = 0;
				tempPoint.x = i;

				pathCrewmate = findPath(crewmate, tempPoint);
				pathNecromancer = findPath(necromancer, tempPoint);

				newTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);

				if (newTime > bestTime) {
					return bestTime;
				}

				bestTime = newTime;
			}
		}

		bestTime = newTime;
	}

	return bestTime;
}

int main()
{
	int rows = 0;

	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		double result = 0;

		Point necromancer;
		cin >> necromancer.x;
		cin >> necromancer.y;

		Point crewmate;
		cin >> crewmate.x;
		cin >> crewmate.y;

		double speedBot = 0;
		double speedTop = 0;

		cin >> speedBot;
		cin >> speedTop;

		Point middlePoint;
		middlePoint.y = 0;

		if (speedBot < speedTop) {

			middlePoint.x = necromancer.x;

			result = findBestTime(middlePoint, necromancer, crewmate, speedTop, speedBot);
			/*double pathCrewmate = findPath(crewmate, middlePoint);
			double pathNecromancer = findPath(necromancer, middlePoint);

			bestTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);

			result = bestTime;*/
		}
		else if (speedBot > speedTop) {
			middlePoint.x = crewmate.x;

			result = findBestTime(middlePoint, necromancer, crewmate, speedTop, speedBot);
			/*double pathCrewmate = findPath(crewmate, middlePoint);
			double pathNecromancer = findPath(necromancer, middlePoint);

			bestTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);

			result = bestTime;*/
		}
		else {
			middlePoint.x = crewmate.x;

			result = findBestTime(middlePoint, necromancer, crewmate, speedTop, speedBot);
			/*double pathCrewmate = findPath(crewmate, middlePoint);
			double pathNecromancer = findPath(necromancer, middlePoint);

			bestTime = calculateTime(pathCrewmate, speedTop) + calculateTime(pathNecromancer, speedBot);

			result = bestTime;*/
		}

		//if (crewmate.y > 0) {
		//	if (speedV1 < speedV2TDD) {

		//		double wholeHeightOfPoints = abs(crewmate.y) + abs(necromancer.y);

		//		double heightOfTheFastes = abs(crewmate.y);

		//		double a = abs(crewmate.x);

		//		double b = abs(necromancer.x);

		//		if (a == b) {
		//			a = 0;
		//			b = 0;
		//		}

		//		result = sqrt(pow(heightOfTheFastes, 2) + pow(a, 2)) / speedV2TDD + sqrt(pow(b, 2) + pow((wholeHeightOfPoints - heightOfTheFastes), 2)) / speedV1;

		//		//Bottom part is slower
		//		/*betweenDimensions.x = necromancer.x;

		//		double shortestPathA = findShortestPath(necromancer, betweenDimensions);
		//		double shortestPathB = findShortestPath(betweenDimensions, crewmate);

		//		double timeSpeedShortestPathA = shortestPathA / speedV1;
		//		double timeSpeedShortestPathB = shortestPathB / speedV2TDD;

		//		result = timeSpeedShortestPathA + timeSpeedShortestPathB;*/
		//	}
		//	else {
		//		//Top part is slower
		//		// L,x,a,b

		//		double wholeHeightOfPoints = abs(crewmate.y) + abs(necromancer.y);

		//		double heightOfTheFastes = abs(necromancer.y);

		//		double a = abs(necromancer.x);

		//		double b = abs(crewmate.x);

		//		if (a == b) {
		//			a = 0;
		//			b = 0;
		//		}


		//		result = sqrt(pow(heightOfTheFastes, 2) + pow(a, 2)) / speedV1 + sqrt(pow(b, 2) + pow((wholeHeightOfPoints - heightOfTheFastes), 2)) / speedV2TDD;

		//		/*	betweenDimensions.x = crewmate.x;


		//			double shortestPathA = findShortestPath(crewmate, betweenDimensions);
		//			double shortestPathB = findShortestPath(betweenDimensions, necromancer);

		//			double timeSpeedShortestPathA = shortestPathA / speedV2TDD;
		//			double timeSpeedShortestPathB = shortestPathB / speedV1;

		//			result = timeSpeedShortestPathA + timeSpeedShortestPathB;*/
		//	}
		//}

		//T = sqrt(x^2+a^2/v1 + sqrr(b^2 + (l - x) ^ 2 / v2))

		printf("%.5f \r\n", result);
	}

	return 0;
}
