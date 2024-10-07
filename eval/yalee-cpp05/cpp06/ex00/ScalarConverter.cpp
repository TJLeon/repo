#include "ScalarConverter.hpp"

Omnivar ScalarConverter::converter(string param)
{
    Omnivar omnivar;

    Type type = getType(param);
    switch (type) {
        case POSITIVE_INF:
        {
            omnivar.t_char = 0;
            omnivar.t_double = +INFINITY;
            omnivar.t_float = +INFINITY;
            omnivar.t_int = 0;
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: +inff" << endl;
            cout << "double: +inf" << endl;
            break;
        }
        case NEGATIVE_INF:
        {
            omnivar.t_char = 0;
            omnivar.t_double = -INFINITY;
            omnivar.t_float = -INFINITY;
            omnivar.t_int = 0;
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: -inff" << endl;
            cout << "double: -inf" << endl;
            break;
        }
        case NANF:
        {
            omnivar.t_char = 0;
            omnivar.t_double = 0;
            omnivar.t_float = 0;
            omnivar.t_int = 0;
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: nanf" << endl;
            cout << "double: nan" << endl;
            break;
        }
        case FLOAT:
        {
            omnivar.t_float = std::stof(param);
            omnivar.t_char = static_cast<char>(omnivar.t_float);
            omnivar.t_double = static_cast<double>(omnivar.t_float);
            omnivar.t_int = static_cast<int>(omnivar.t_float);
            if (omnivar.t_char < 32 || omnivar.t_char > 126)
                cout << "char: unprintable!" << endl;
            else
                cout << "char: " << omnivar.t_char << endl;
            cout << "int: " << omnivar.t_int << endl;
            cout << "float: " << omnivar.t_float << endl;
            cout << "double: " << omnivar.t_double << endl;
            break;
        }
        case DOUBLE:
        {
            omnivar.t_double = std::stod(param);
            omnivar.t_float = static_cast<float>(omnivar.t_double);
            omnivar.t_char = static_cast<char>(omnivar.t_double);
            omnivar.t_int = static_cast<int>(omnivar.t_double);
            if (omnivar.t_char < 32 || omnivar.t_char > 126)
                cout << "char: unprintable!" << endl;
            else
                cout << "char: " << omnivar.t_char << endl;
            cout << "int: " << omnivar.t_int << endl;
            cout << "float: " << omnivar.t_float << endl;
            cout << "double: " << omnivar.t_double << endl;
            break;
        }
        case CHAR:
        {
            omnivar.t_char = param[0];
            omnivar.t_double = static_cast<double>(omnivar.t_char);
            omnivar.t_float = static_cast<float>(omnivar.t_char);
            omnivar.t_int = static_cast<int>(omnivar.t_char);
            if (omnivar.t_char < 32 || omnivar.t_char > 126)
                cout << "char: unprintable!" << endl;
            else
                cout << "char: " << omnivar.t_char << endl;
            cout << "int: " << omnivar.t_int << endl;
            cout << "float: " << omnivar.t_float << endl;
            cout << "double: " << omnivar.t_double << endl;
            break;
        }
        case INT:
        {
            omnivar.t_int = std::stoi(param);
            omnivar.t_char = static_cast<char>(omnivar.t_int);
            omnivar.t_double = static_cast<double>(omnivar.t_int);
            omnivar.t_float = static_cast<float>(omnivar.t_int);
            if (omnivar.t_char < 32 || omnivar.t_char > 126)
                cout << "char: unprintable!" << endl;
            else
                cout << "char: " << omnivar.t_char << endl;
            cout << "int: " << omnivar.t_int << endl;
            cout << "float: " << omnivar.t_float << endl;
            cout << "double: " << omnivar.t_double << endl;
            break;           
        }
    }
    return omnivar;
}

Type ScalarConverter::getType(string param)
{
    if (param == "+inff" || param == "+inf")
        return (POSITIVE_INF);
    else if (param == "-inf" || param == "-inff")
        return (NEGATIVE_INF);
    else if (param == "nanf" || param == "nan")
        return (NANF);

    int i = 0;
    while (param[i])
    {
        if (param[i] == '.')
        {
            if (param.back() == 'f')
                return (FLOAT);
            else
                return (DOUBLE);
        }
        if (param[i] >= '0' && param[i] <= '9')
            i++;
        else
            return (CHAR);
    }
    return (INT);
}
