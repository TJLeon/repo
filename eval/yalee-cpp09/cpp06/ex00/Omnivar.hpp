#ifndef OMNIVAR_HPP
#define OMNIVAR_HPP

enum Type {
    CHAR = 0,
    INT = 1,
    DOUBLE = 2,
    FLOAT = 3,
    POSITIVE_INF = 4,
    NEGATIVE_INF = 5,
    NANF = 6
};

class Omnivar {
public:
    char t_char;
    int t_int;
    float t_float;
    double t_double;
};

#endif