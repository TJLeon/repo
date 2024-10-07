#include "Zombie.hpp"

Zombie::Zombie()
{
    cout << "This is a default constructor. " << endl;
}

Zombie::Zombie(string name)
{
    Zombie::name = name;
    cout << "This is a constructor that takes in a string. " << endl << "declared as Zombie(std::string); " << endl << Zombie::name << " is created. " << endl;
}

Zombie::~Zombie()
{
    cout << Zombie::name << " is destroyed. " << endl;
}

void Zombie::announce()
{
    cout << Zombie::name << ": Braaiiiinzzzz.... " << endl;
}

void Zombie::setName(string name)
{
    Zombie::name = name;
}