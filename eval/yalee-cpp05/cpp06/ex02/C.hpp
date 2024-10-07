#ifndef C_HPP
#define C_HPP

#include "Base.hpp"
class C : public Base {
private:
    const string type;
public:
    C();
    ~C();
    void whoMe();
};

#endif