#ifndef FWPMANIPULATOR_H
#define FWPMANIPULATOR_H

#include <iostream>

class FWPManipulator
{
    public:
        FWPManipulator(unsigned width = 5, unsigned precision = 2, char fillChar = ' ');

        void operator()(std::ostream&) const;

        // overloading operator <<
        friend std::ostream& operator << (std::ostream&, const FWPManipulator&);
    private:
        unsigned width, precision;
        char fillChar;
};

#endif // FWPMANIPULATOR_H
