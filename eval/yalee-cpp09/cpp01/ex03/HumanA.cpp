#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(string name, Weapon& weapon) : equipedWeapon(weapon)
{
    cout << "constructor for HumanA" << endl;
    HumanA::name = name;
}

// HumanA::HumanA(string name, Weapon* weapon)
// {
//     HumanA::name = name;
//     HumanA::equipedWeapon = weapon;
// }
// void HumanA::setWeapon(Weapon weapon)
// {
//     HumanA::equipedWeapon = &weapon; 
// }

// void HumanA::attack()
// {
//     cout << name << " attacks with their " << HumanA::equipedWeapon->getType() << endl;
// }

HumanA::~HumanA()
{
    cout << "destructor for HumanA" << endl;
}

void HumanA::setName(string name)
{
    HumanA::name = name;
}

void HumanA::setWeapon(Weapon weapon)
{
    HumanA::equipedWeapon = weapon; 
}


void HumanA::attack()
{
    cout << name << " attacks with their " << HumanA::equipedWeapon.getType() << endl;
}