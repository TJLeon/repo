#include "zombie.hpp"

Zombie::Zombie(std::string name)
{
    Zombie::name = name;
    std::cout << "constructor for " << Zombie::name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "destructor for " << Zombie::name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiinnnzzzZZZ....." << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie(name);
    return zombie;
}

void randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}