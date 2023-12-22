#include <iostream>

#include "Library.h"

Library::Library(size_t cap) : capacity(cap), count(0)
{
	this->books = new Book[capacity];
}

Library::Library(const Library& other)
{
	copyLibrary(other);
}

Library& Library::operator=(const Library& other)
{
	if(this != &other)
	{
		// освобождаване на паметта, 
		// с която текущо е свързан обекта
		delete[] this->books;

		copyLibrary(other);
	}

	return *this;
}

Library::~Library()
{
	delete[] this->books;
}

// копиране на информацията от обекта, 
// подаден като аргумент в текущия 
void Library::copyLibrary(const Library& other)
{
	this->capacity = other.capacity;
	this->count = other.count;

	this->books = new Book[this->capacity];
	for(size_t i = 0; i < this->count; ++i)
	{
		this->books[i] = other.books[i];
	}
}

bool Library::resize()
{
	this->capacity = (this->capacity == 0) ? 1 : 2 * this->capacity;

	// опитваме се да заделим нов блок памет
	Book* buffer = new (std::nothrow) Book[this->capacity];
	// ако операцията по заделяне на памет не е успешна
	if(!buffer) return false;

	// копиране на обектите от старата памет в новата
	for(size_t i = 0; i < this->count; ++i)
	{
		buffer[i] = this->books[i];
	}

	// освобождаване на старата памет
	delete[] this->books;
	// свързваме член-данната books с новата памет
	this->books = buffer;

	return true;
}

// добавяне на нова книга в библиотеката
bool Library::addBook(const Book& newBook)
{
	// ако няма място, преоразмеряваме масива с книги
	if(this->count == this->capacity)
	{
		if(!resize())
			return false;
	}

	this->books[this->count] = newBook;
	++this->count;

	return true;
}

// премахване на книга, книгата се търси по ISBN
bool Library::removeBook(const char* isbn)
{
	// да се провери дали книга с посочения isbn се съдържа в масива
	// ако да, да се премахне
	// вариант 1: разменя с последната и се намалява броя
	// вариант 2: всички след нужната позиция се изместват с една позиция наляво 
	// и се намалява броя
	return false;
}

// търси книга по isbn,
// ако я открие, връща индекса на книгата, в противен случай -1
int Library::findBooksIndexByISBN(const char* isbn) const
{
	return -1;
}

// индексиране на книгите в библиотеката
Book* Library::getBookByIndex(size_t index)
{
	if (index < 0 || index >= this->getBooksCount())
		return NULL;

	return this->books + index;
}
// за константни обекти
const Book* Library::getBookByIndex(size_t index) const
{
	if (index < 0 || index >= this->getBooksCount())
		return NULL;

	return this->books + index;
}

void Library::print() const
{
	std::cout << "List of the books in the library: " << std::endl;
	for (size_t i = 0; i < this->count; ++i)
	{
		this->books[i].print();
	}
}