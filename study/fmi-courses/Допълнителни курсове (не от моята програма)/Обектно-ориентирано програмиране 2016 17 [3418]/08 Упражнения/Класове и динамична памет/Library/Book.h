#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

class Book
{
	public:
		// конструктор по подразбиране
		Book();
		// конструктор с аргументи
		Book(const char* title, const char* author, const char* isbn, unsigned pages);
		// копиращ конструктор
		Book(const Book&);
		// операция за присвояване
		Book& operator=(const Book&);
		// деструктор
		~Book();

		// селектори
		// функции за достъп до член-данните
		const char* getTitle() const
		{
			return (this->title == NULL) ? "" : this->title;
		}

		const char* getAuthor() const
		{
			return (this->author == NULL) ? "" : this->author;
		}

		const char* getISBN() const
		{
			return this->isbn;
		}

		unsigned getCountPages() const
		{
			return this->countPages;
		}

		// мутатори
		// функции за промяна на член-данните
		void setTitle(const char*);
		void setAuthor(const char*);
		void setISBN(const char*);
		void setPages(unsigned);

		// извеждане на стандартния изход
		void print() const;

	private:
		// помощна функция за валидиране на ISBN
		bool isValidISBN(const char*);
		// помощна функция за заделяне на памет и инициализиране на член-данни
		// имаме повече от една член-данна, които са динамични низове
		void setNewValue(char*& dest, const char* src);

	private:
		char* title;
		char* author;
		
		char isbn[15];
		unsigned countPages;
};


#endif // BOOK_H_INCLUDED