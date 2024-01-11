#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"

class Library
{
	public:
		Library(size_t cap = 1); 
		Library(const Library&);
		Library& operator=(const Library&);
		~Library();

		size_t getCapacity() const { return this->capacity; }
		size_t getBooksCount() const { return this->count; }

		// не добавяме мутатори за броя на книгите и капацитета
		// те ще бъдат променяни във функциите, които добавят и премахват книги

		// добавяне на книга в библиотеката
		bool addBook(const Book&);
		// премахване на книга, книгата се търси по ISBN
		bool removeBook(const char* isbn);
		int findBooksIndexByISBN(const char* isbn) const;

		// индексиране на книгите в библиотеката
		Book* getBookByIndex(size_t index);
		// за константни обекти
		const Book* getBookByIndex(size_t index) const;

		void print() const;

	private:
		// помощна функция за промяна на капацитета на библиотеката и заделяне на нова памет
		bool resize();
		// помощна функция за копиране на информацията от друга библиотека
		void copyLibrary(const Library&);

	private:
		// динамичен масив от книги
		Book* books;

		// колко е капацитетът на библиотеката
		size_t capacity;
		// колко е реалният брой книги в библиотеката
		size_t count;
};

#endif