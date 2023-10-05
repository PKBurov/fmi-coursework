#include "FWPManipulator.h"

#include <iomanip>

FWPManipulator::FWPManipulator(unsigned width, unsigned precision, char fillChar)
    : width(width), precision(precision), fillChar(fillChar)
{
    // check if width is less than the specified precision
}

void FWPManipulator::operator()(std::ostream& out) const
{
    out << std::setw(width) << std::setfill(fillChar)
        << std::setiosflags(std::ios::fixed) << std::setprecision(precision);
}

std::ostream& operator << (std::ostream& out, const FWPManipulator& m)
{
    m(out);

    return out;
}
