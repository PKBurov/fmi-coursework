#include <iostream>
#include <cstring>

#include "Book.h"

Book::Book() : title(NULL), author(NULL), countPages(0)
{
	// isbn е празен низ
	this->isbn[0] = '\0';
}

// помощна функция, която служи за заделяне на памет
// и инициализирането й с определен низ
void Book::setNewValue(char*& dest, const char* src)
{
	// ако източникът на информация е NULL
	if(!src)
	{
		// освобождаваме паметта, с която е свързан dest
		delete[] dest;
		dest = NULL;

		return;
	}

	// колко памет ни е необходима?
	// колкото е дължината на низа, от който ще копираме 
	// + 1 за терминираща 0
	size_t length = strlen(src) + 1;

	// заделяме памет...
	char* buffer = new char[length];
	// копираме информацията в буфера...
	// в CodeBlocks може да използвате strcpy 
	// или strncpy (+ сложете терминиращата нула в края на низа)
	strcpy_s(buffer, length, src);

	// ако заделянето на паметта и копирането са били успешни,
	// освобождаваме старото съдържание на dest
	delete[] dest;
	// ... и се свързваме с новото
	dest = buffer;
}

void Book::setTitle(const char* t)
{
	setNewValue(this->title, t);
}

void Book::setAuthor(const char* a)
{
	setNewValue(this->author, a);
}

void Book::setISBN(const char* isbn)
{
	if(isValidISBN(isbn))
	{
		strcpy_s(this->isbn, 15, isbn);
	}
	else
	{
		this->isbn[0] = '\0';
	}
}

void Book::setPages(unsigned p)
{
	this->countPages = p;
}

// в инициализиращия списък свързваме указателите title и author с NULL,
// тъй като във функцията setNewValue преди да се свържем с новата памет
// се опитваме да освободим старата памет, с която са свързани указателите

// това е конструктор, т.е. за член-данните все още не е заделена памет, 
// обектът все още не е създаден

// ако указателите са нулирани, delete всъщност няма да се включи, 
// няма какво да се освобождава, избягваме възможни проблеми 
// с опит за освобождаване на случайна памет
Book::Book(const char* title, const char* author, const char* isbn, unsigned pages)
	:title(NULL), author(NULL)
{
	setNewValue(this->title, title);
	setNewValue(this->author, author);

	this->setISBN(isbn);
	this->setPages(pages);
}

// не забравяйте & и const при подаването на обекта
Book::Book(const Book& other)
	:title(NULL), author(NULL)
{
	setNewValue(this->title, other.getTitle());
	setNewValue(this->author, other.getAuthor());

	this->setISBN(other.getISBN());
	this->setPages(other.getCountPages());
}

// операция за присвояване
Book& Book::operator=(const Book& other)
{
	// проверка за самоприсвояване
	if(this != &other)
	{
		setNewValue(this->title, other.getTitle());
		setNewValue(this->author, other.getAuthor());

		this->setISBN(other.getISBN());
		this->setPages(other.getCountPages());
	}

	return *this;
}

// в деструктора се освобождава динамичната памет,
// която сме заделили в конструкторите
Book::~Book()
{
	delete[] this->title;
	delete[] this->author;
}

bool Book::isValidISBN(const char* isbn)
{
	while(*isbn)
	{
		if(*isbn < '0' || *isbn > '9')
			return false;

		++isbn;
	}

	return true;
}

void Book::print() const
{
	std::cout << "Title: " 
		<< this->getTitle() << std::endl;

	std::cout << "Author: "
		<< this->getAuthor() << std::endl;

	std::cout << "ISBN: " << this->getISBN() << std::endl;
	std::cout << "Pages: " << this->getCountPages() << std::endl;
}
