#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
	public:
		// конструктор по подразбиране, 
		// инициализира обекта с датата 01.01.1900
		Date();
		// конструктор с аргументи
		// ако подадените аргументи образуват валидна дата, 
		// ще бъдат използвани за съдаване на обект,
		// в противен случай ще се използват стойности 
		// по подразбиране (ден: 1, месец: 1, година: 1900)
		Date(unsigned day, unsigned month, unsigned year);
		// деструктор
		~Date();

		// селектори
		// член-функции, които дават достъп до член-данните на класа
		unsigned getDay() const; 
		unsigned getMonth() const;
		unsigned getYear() const;

		// да се дефинира функция, която определя кой ден седмицата 

		// член-функции, които променят стойностите на член-данните
		void setDay(unsigned);
		void setMonth(unsigned);
		void setYear(unsigned);

		// извеждане на датата на стандартния изход
		void print() const;
	
	private:
		// помощна функция, която проверява дали се образува валидна дата
		bool isValid(unsigned day, unsigned month, unsigned year) const;
		bool isLeapYear(unsigned year) const;
		// могат да се добавят и други помощни функции...
	
	private:
		unsigned day, month, year;
};

inline unsigned Date::getDay() const
{ return this->day; }

inline unsigned Date::getMonth() const
{ return this->month; }

inline unsigned Date::getYear() const
{ return this->year; }

#endif // DATE_H_INCLUDED