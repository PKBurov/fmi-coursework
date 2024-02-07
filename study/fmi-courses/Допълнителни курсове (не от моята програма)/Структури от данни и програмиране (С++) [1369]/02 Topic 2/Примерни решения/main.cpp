#include <iostream>
#include <iomanip>

#include "FWPManipulator.h"

// cout << fixedprecision << number;
// it is possible because of the ovverloaded operator <<
// with argument pointer to a function:
// basic_ostream& operator<<( std::basic_ostream& (*func)(std::basic_ostream&) );
std::ostream& fixedprecision(std::ostream& out)
{
    out << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    return out;
}

void testStreamState()
{
    double number;
    while(std::cin >> number)
    {
        // an object of FWPManipulator should be created...
        std::cout << FWPManipulator() << number << std::endl;
    }

    std::cout << "The End!" << std::endl;
}

int main()
{
    const double PI = 3.14159265;

    std::cout << FWPManipulator(6, 3, '*') << PI << std::endl;

    testStreamState();

    return 0;
}
