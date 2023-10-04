#include <iostream>
#include <stdexcept>

// за да проследим създаването и унищовашането на обектите...
class Test
{
	public:
		Test()
		{
			// some resources are acquired
			std::cout << "Test()" << std::endl;
		}

		~Test()
		{
			// the acquired resources should be released
			std::cout << "~Test()" << std::endl;
		}
};

enum ExceptionType
{
	INT,
	DOUBLE,
	STRING,
	OBJECT
};

void throwingException(ExceptionType type)
{
	switch (type)
	{
		case INT:
			throw 1;

		case DOUBLE:
			throw 2.0;
		
		case STRING:
			throw "The reason for the exception...";
		
		case OBJECT:
			throw std::out_of_range("Out of range exception!");
		
		default:
			throw std::exception("Unexpected exception!");
	}
}

int catchAndRethrowIfInt(ExceptionType type)
{
	try
	{
		// ще бъде извикан деструкторът на обекта
		// след прихващането на съобщението
		Test t;

		throwingException(type);
	}
	catch (int& ex)
	{
		std::cout << "Int exception: " << ex << std::endl;

		throw;
	}
	catch (double& ex)
	{
		std::cout << "Double exception: " << ex << std::endl;
	}
	catch(const char* ex)
	{
		std::cout << "Exception was thrown!" << std::endl;
		std::cout << ex << std::endl;
	}
	catch (std::out_of_range& ex)
	{
		std::cout << "out_of_range exception: " << ex.what() << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

int main()
{
	// изкльчението ще бъде обработено във функцията
	catchAndRethrowIfInt(OBJECT);

	int* arr = NULL;
	try
	{
		// къде ще бъде освободена тази динамична памет?
		arr = new int[5];

		catchAndRethrowIfInt(INT);

		// няма да се достигне до тук
		std::cout << "Clear the memory of the array..." << std::endl;
		delete[] arr;
	}
	catch(int& ex)
	{
		std::cout << "The memory is released in the catch block" << std::endl;
		delete[] arr;

		std::cout << "The rethrown exception was caught: " << ex << std::endl;
	}

	return 0;
}