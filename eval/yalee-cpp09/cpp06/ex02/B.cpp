#include "B.hpp"

B::B() : type("type = B")
{
    cout << "B created" << endl;
}

B::~B()
{
    cout << "B default destructor" << endl;
}

void B::whoMe()
{
    cout << this->type << endl;
}