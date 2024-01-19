#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <cmath>

// клас, описващ точка в декартова координатна система...
class Point
{
	public:

		// конструктор по подразбиране
		// Point();

		// конструктор с аргументи по подразбиране
		// ако не се подаде нито един аргумент при извикване на конструктора, 
		// ще се използват подразбиращите се стойности 

		// може да замени конструктора по подразбиране
		Point(double = 0, double = 0);

		// функции за промяна на член-данните
		void setX(double newX) { this->x = newX; }
		void setY(double newY) { this->y = newY; }

		// функции за достъп до член-данните
		double getX() const { return this->x; }
		double getY() const { return this->y; }

		// намиране на разстоянието между две точки...
		// едната е тек. аргумент, върху който се прилага функцията, 
		// а втората точка се предава като аргумент 
		double distance(const Point& other) const;

		void print() const;

	private:
		double x, y;
};

#endif // !POINT_H_INCLUDED

