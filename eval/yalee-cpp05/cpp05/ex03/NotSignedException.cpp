#include "NotSignedException.hpp"

const char *NotSignedException::what() const throw()
{
    return("Form not signed");
}