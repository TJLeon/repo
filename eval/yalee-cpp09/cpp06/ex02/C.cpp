#include "C.hpp"

C::C(): type("type = C")
{
    cout << "C created" << endl;
}

C::~C()
{
    cout << "C default destructor" << endl;
}

void C::whoMe()
{
    cout << this->type << endl;
}