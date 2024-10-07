#include "FragTrap.hpp"

#include <iostream>

using namespace std;

FragTrap::FragTrap(): ClapTrap()
{
	cout << "FragTrap Default Constructor Called" << endl;
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
}

FragTrap::FragTrap(string name): ClapTrap(name)
{
	cout << "FragTrap Constructor Called" << endl;
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
}


FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap)
{
	cout << "FragTrap Copy constructor called" << endl;
	*this = fragtrap;
}

FragTrap &FragTrap::operator = (const FragTrap &fragtrap)
{
	cout << "FragTrap Copy assignment operator called" << endl;
	if (this == &fragtrap)
		return (*this);
	this->name = fragtrap.name;
	this->hp = fragtrap.hp;
	this->ep = fragtrap.ep;
	this->atk = fragtrap.atk;
	return (*this);
}

FragTrap::~FragTrap()
{
	cout << "FragTrap Destructor Called" << endl;
}

void	FragTrap::attack(const string &target)
{
	if (ep <= 0)
		cout << "FragTrap " << name << " tried to attack " << target << ", but it has no energy points!" << endl;
	else if (hp <= 0)
		cout << "FragTrap " << name << " cannot attack " << target << " because it is dead!" << endl;
	else
	{
		ep -= 1;
		cout << "FragTrap " << name << " attacks " << target << ", dealing " << atk << " points of damage!" << endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	cout << "FragTrap " << name << " wants to high five!" << endl;
}