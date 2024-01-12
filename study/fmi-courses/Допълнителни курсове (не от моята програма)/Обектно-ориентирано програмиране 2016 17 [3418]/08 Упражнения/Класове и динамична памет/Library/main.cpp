#include <iostream>

#include "Book.h"
#include "Library.h"

void testBooks()
{
	Book empty;
	empty.print();

	// невалиден ISBN
	Book atlas("Atlas Shrugged", "Ayn Rand", "a", 1350);
	atlas.print();

	// използва се оператора за присвояване = 
	// и двата обекта са вече създадени
	empty = atlas;
	empty.print();

	empty.setTitle("Harry Potter");
	empty.print();

	// обектът copy се дефинира сега,
	// за да бъде създаден се използва копиращ конструктор
	Book copy = atlas;
	copy.print();
}


void testLibrary()
{
	Library mine;
	
	Book atlas("Atlas Shrugged", "Ayn Rand", "1", 1350);
	mine.addBook(atlas);

	mine.print();

	std::cout << "--- Copy ctor ---" << std::endl;
	Library copy = mine;
	copy.print();

	std::cout << "--- Add new book ---" << std::endl;
	Book sharingKnife("Beguilement", "Lois McMaster Bujold", "3", 389);
	copy.addBook(sharingKnife);
	copy.print();

	std::cout << "--- operator = ---" << std::endl;
	mine = copy;
	mine.print();
}


int main()
{
	//testBooks();
	
	testLibrary();

	return 0;
}