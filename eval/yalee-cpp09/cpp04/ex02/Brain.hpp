#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

using namespace std;

class Brain{
public:
    Brain();
    Brain(const Brain &brain);
    Brain &operator = (const Brain &brain);
    ~Brain();

    string ideas[100];
};

#endif