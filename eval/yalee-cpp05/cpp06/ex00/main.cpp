#include "ScalarConverter.hpp"
#include <sstream>

using std::stringstream;

int main (int argc, char **argv)
{
    (void)argc;
    ScalarConverter::converter(argv[1]);
}