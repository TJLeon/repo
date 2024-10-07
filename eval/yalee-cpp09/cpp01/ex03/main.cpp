#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

using namespace std;

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        // Weapon stick = Weapon("big stick");
        HumanA bob("Bob", club);
        // HumanA bob("Bob", &club);
        bob.attack();
        club.setType("some other type of club");
        // bob.setWeapon(stick);
        // cout << club.getType() << endl;
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}