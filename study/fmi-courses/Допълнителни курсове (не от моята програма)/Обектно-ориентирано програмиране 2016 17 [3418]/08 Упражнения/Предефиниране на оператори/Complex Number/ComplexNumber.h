#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

// клас, описващ комплексно число
class ComplexNumber
{
	public:
		// конструктор с аргументи по подразбиране
		// може да замени подразбиращия се 
		ComplexNumber(double newRe = 0, double newIm = 0);

		// селектори, функции за достъп до член-данните
		double getRe() const { return this->re; }
		double getIm() const { return this->im; }
		
		// мутатори, променят стойностите на член-данните
		void setRe(double newRe) { this->re = newRe; }
		void setIm(double newIm) { this->im = newIm; }

		// сумиране на две комплексни числа
		// += променя текущия обект
		ComplexNumber& operator+=(const ComplexNumber& right);
		// изваждане на две комплексни числа
		ComplexNumber& operator-=(const ComplexNumber& right);
		ComplexNumber& operator*=(const ComplexNumber& right);
		
		// проверява дали комплексното число е 0
		bool operator!() const;
		// намира комплексно спрегнатото на дадено комплексно число
		ComplexNumber operator-() const;

		// намира модула на комплексното число
		// оператор за преобразуване до реално число
		// типът на резултата не се указва, 
		// защото съвпада с типа, до който преобразуваме
		explicit operator double() const;

		// префиксна операция ++
		ComplexNumber& operator++();

		// постфиксна операция ++
		// за да се различава от префиксната, се декларира един dummy аргумент
		// операцията връща старата стойност на обекта
		ComplexNumber operator++(int);
	private:
		// член-данни - реална и имагинерна част
		double re, im;
};

// операции за сравнение на две комплексни числа
bool operator==(const ComplexNumber& left, const ComplexNumber& right);
bool operator!=(const ComplexNumber& left, const ComplexNumber& right);

// + създава нов обект, левият и десният операнди не се променят
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
// събиране на комплексно число с реално число
// левият операнд е комплексното число, 
// операцията може да бъде декларирана в класа
//ComplexNumber operator+(const ComplexNumber& left, double right);

// събиране на реално и комплексно число,
// операцията е комутативна
// левият операнд е реалното число, 
// функцията задължително трябва да бъде външна
ComplexNumber operator+(double left, const ComplexNumber& right);

// комутативна операция
ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right);
//ComplexNumber operator*(const ComplexNumber& left, double right);
ComplexNumber operator*(double left, const ComplexNumber& right);

ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right);

// предефиниране на оператора за изход
std::ostream& operator<<(std::ostream& out, const ComplexNumber& complexNumber);

#endif // !COMPLEXNUMBER_H_INCLUDED


