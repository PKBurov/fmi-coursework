#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

// клас, описваща комплексно число
class ComplexNumber
{
	public:
		// конструктор по подразбиране
		ComplexNumber();
		// конструктор с аргументи
		ComplexNumber(double, double);

		// селектори, функции за достъп до член-данните
		
		// функциите са константни (const след скобите с аргументи),
		// тъй като не променят текущия обект

		// this е указател към текущия обект, 
		// върху който е приложена функцията
		// неявен аргумент на всяка член-фунцкия на класа
		double getRe() const { return this->re; }
		double getIm() const { return this->im; }
		
		// функция, която извежда комплексното число на стандарния изход
		// текущият обект не се променя
		void print() const;
		
		// мутатори, променят стойностите на член-данните
		void setRe(double newRe) { this->re = newRe; }
		void setIm(double newIm) { this->im = newIm; }

		// операции с комплексни числа

		// функция, която проверява дали две комплексни числа са равни
		// едното комплексно число е текущият обект, 
		// върху който е приложена функцията, второто е аргументът
		bool equals(const ComplexNumber&) const;

		// функция, която намира сумата на две комплексни числа
		ComplexNumber add(const ComplexNumber&) const;
		// функция, която намира разликата на две комплексни числа
		ComplexNumber substract(const ComplexNumber&) const;
		// функция, която умножава две комплексни числа
		ComplexNumber multiply(const ComplexNumber&) const;

		// функция, която намира комплексно спрегнатото на дадено комплексно число
		ComplexNumber conjugate() const;
	private:
		// член-данни - реална и имагинерна част
		double re, im;
};

#endif // !COMPLEXNUMBER_H_INCLUDED



