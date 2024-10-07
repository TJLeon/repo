#ifndef INVALIDEXCEPTION_HPP
#define INVALIDEXCEPTION_HPP

#include <exception>
#include <iostream>
#include <string>

using std::exception;
using std::string;

class NotSignedException: public exception
{
public:
    const char *what() const throw();
};
#endif