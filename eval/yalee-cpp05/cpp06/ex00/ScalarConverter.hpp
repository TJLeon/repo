#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include "Omnivar.hpp"

using std::string;
using std::cout;
using std::endl;

class ScalarConverter {
public:
    static Omnivar converter(string param);
private:
    static Type getType(string param);
};

#endif