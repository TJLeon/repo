#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB{
public:
    HumanB(string name);
    ~HumanB();
    void setName(string name);
    void setWeapon(Weapon &weapon);
    void attack();
private:
    string name;
    Weapon* equipedWeapon;
};

#endif