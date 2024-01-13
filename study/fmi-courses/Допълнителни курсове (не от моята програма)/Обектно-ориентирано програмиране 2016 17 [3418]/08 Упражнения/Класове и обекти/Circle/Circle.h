#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Point.h"

// клас, описващ окръжност с характеристики център на окръжността и радиус
// центърът на окръжността е ТОЧКА
// радиусът на окръжността трябва да бъде неотрицателно число

class Circle
{
	public:
		// конструктор по подразбиране
		Circle();
		// конструктор с аргументи
		Circle(const Point&, double);

		// селектори
		Point getCenter() const { return this->center; }
		double getRadius() const { return this->radius; }

		// мутатори
		void setCenter(const Point&);
		void setCenter(double, double);

		void setRadius(double);

		// дефинирайте функция, която проверява дали 
		// две окръжности се пресичат

		// дефинирайте функция, която проверява дали дадена
		// точка се съдържа в окръжността

		void print() const;

	private:
		// вграждане на обект от клас Point
		Point center;
		double radius;
};

#endif // !CIRCLE_H_INCLUDED

