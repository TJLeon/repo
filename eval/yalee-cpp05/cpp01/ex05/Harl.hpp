#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Harl{
public:
    Harl();
    ~Harl();
    void complain(string level);
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif