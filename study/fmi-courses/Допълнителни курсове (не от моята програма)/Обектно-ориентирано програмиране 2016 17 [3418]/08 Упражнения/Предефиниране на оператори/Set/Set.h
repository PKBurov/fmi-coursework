#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <iostream>

// крайно множество от цели числа
class Set
{
	public:
		// за да не се използва за не€вни преобразувани€
		explicit Set(size_t capacity = 1);
		Set(const Set&);
		Set& operator=(const Set&);
		~Set();

		//селектори
		size_t getElementsCount() const { return this->count; }
		size_t getCapacity() const { return this->capacity; }

		// предефиниране на операции
		
		// оператор за индексиране
		int& operator[](size_t index);
		// константна верси€ на оператора
		const int& operator[](size_t index) const;

		// operator(), с аргумент ц€ло число
		// провер€ва дали елементът принадлежи на множеството
		
		// може да връща позици€та, на ко€то е намерен елемента 
		// или -1, ако елементът не е част от множеството
		bool operator()(int elem) const;

		// провер€ва дали множеството не е празно
		bool operator!() const;

		// добав€ елемент към множеството
		Set& operator+=(int);
		// обединение на множества
		Set& operator+=(const Set&);

		// премахва елемент от множеството
		Set& operator-=(int);
		// разлика на две множества
		Set& operator-=(const Set&);

		// сечение на две множества
		Set& operator*=(const Set&);
		
	private:
		void copy(const Set&);
		void resize();

		// елементите на множеството
		int* elements;
		size_t count;
		size_t capacity;
};

// сравнение на две множества
bool operator==(const Set&, const Set&);
bool operator!=(const Set&, const Set&);

// подмножество
bool operator<(const Set&, const Set&);

Set operator+(const Set&, int);
Set operator+(const Set&, const Set&);

Set operator-(const Set&, int);
Set operator-(const Set&, const Set&);

Set operator*(const Set&, const Set&);

std::ostream& operator<< (std::ostream& out, const Set& set);

#endif // !SET_H_INCLUDED

