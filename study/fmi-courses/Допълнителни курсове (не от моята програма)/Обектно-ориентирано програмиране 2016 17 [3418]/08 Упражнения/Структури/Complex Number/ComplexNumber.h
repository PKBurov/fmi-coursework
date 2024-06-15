#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

// структура, описваща комплексно число
struct ComplexNumber
{
	// член-данни - реална и имагинерна част
	double re, im;
};

// функция, която прочита комплексно число от стандартния вход
void read(ComplexNumber&);
// функция, която извежда комплексното число на стандарния изход
void print(const ComplexNumber&);

// функция, която проверява дали две комплексни числа са равни
bool equal(const ComplexNumber&, const ComplexNumber&);

// функция, която намира сумата на две комплексни числа
ComplexNumber sum(const ComplexNumber&, const ComplexNumber&);
// функция, която намира разликата на две комплексни числа
ComplexNumber substract(const ComplexNumber&, const ComplexNumber&);
// функция, която умножава две комплексни числа
ComplexNumber product(const ComplexNumber&, const ComplexNumber&);

// функция, която намира комплексно спрегнатото на дадено комплексно число
ComplexNumber conjugate(const ComplexNumber&);

#endif // !COMPLEXNUMBER_H_INCLUDED



