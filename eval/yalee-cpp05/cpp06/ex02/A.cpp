#include "A.hpp"

A::A(): type("type = A")
{
    cout << "A created!" << endl;
}

A::~A()
{
    cout << "A default destructor" << endl;
}

void A::whoMe()
{
    cout << this->type << endl;
}