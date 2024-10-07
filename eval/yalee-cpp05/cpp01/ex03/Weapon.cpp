#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
    cout << "default constructor for weapon" << endl;
}

Weapon::~Weapon()
{
    cout << "destructor for weapon" << endl;
}

Weapon::Weapon(string name)
{
    cout << "string constructor for weapon" << endl;
    Weapon::type = name;
}

const string& Weapon::getType()
{
    const string& type = Weapon::type;
    return type;
}

void Weapon::setType(string type)
{
    Weapon::type = type;
}