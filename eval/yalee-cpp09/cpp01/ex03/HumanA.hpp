#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA{
public:
    HumanA(string name, Weapon& weapon);
    ~HumanA();
    void setName(string name);
    void setWeapon(Weapon weapon);
    void attack();
private:
    string name;
    Weapon& equipedWeapon;
};

// class HumanA{
// public:
//     HumanA(string name, Weapon* weapon);
//     ~HumanA();
//     void setName(string name);
//     void setWeapon(Weapon weapon);
//     void attack();
// private:
//     string name;
//     Weapon* equipedWeapon;
// };

#endif