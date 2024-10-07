#ifndef B_HPP
#define B_HPP

#include "Base.hpp"
class B : public Base {
private:
    const string type;
public:
    B();
    ~B();
    void whoMe();
};

#endif