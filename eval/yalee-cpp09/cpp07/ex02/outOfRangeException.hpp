#ifndef OUTOFRANGEEXCEPTION_HPP
#define OUTOFRANGEEXCEPTION_HPP

#include <exception>

class OutOfRange : public std::exception
{
    public:
        const char *what() const throw();
};

#endif