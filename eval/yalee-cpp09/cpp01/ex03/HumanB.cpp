#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(string name)
{
    cout << "constructor for HumanB" << endl;
    HumanB::name = name;
}

HumanB::~HumanB()
{
    cout << "destructor for HumanB" << endl;
}

void HumanB::setName(string name)
{
    HumanB::name = name;
}

void HumanB::setWeapon(Weapon& weapon)
{
    HumanB::equipedWeapon = &weapon;
}

void HumanB::attack()
{
    cout << HumanB::name << " attacks with their " << HumanB::equipedWeapon->getType() << endl;
}