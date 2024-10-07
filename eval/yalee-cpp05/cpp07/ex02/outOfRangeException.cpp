#include "outOfRangeException.hpp"

const char *OutOfRange::what() const throw()
{
    return("out of range!");
}