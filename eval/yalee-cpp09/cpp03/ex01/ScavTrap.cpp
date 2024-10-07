#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	cout << "ScavTrap default constructor" << endl;
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(string name): ClapTrap(name)
{
	cout << "ScavTrap constructor" << endl;
	ScavTrap::name = name;
	ScavTrap::hp = 100;
	ScavTrap::ep = 50;
	ScavTrap::atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ST): ClapTrap(ST)
{
	cout << "Copy constructor" << endl;
	*this = ST;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &ST)
{
	cout << "Copy assignment operator" << endl;
	if (this == &ST)
		return (*this);
	name = ST.name;
	hp = ST.hp;
	ep = ST.ep;
	atk = ST.atk;
	return (*this);
}

void ScavTrap::attack(const string &target)
{
	if (ep <= 0)
		cout << "no energy" << endl;
	else
	{
		cout << "ScavTrap " << name << " attacks " << target
			<< ", causing " << atk << " hit points." << endl;
		ep -= 1;
	}
}

void ScavTrap::guardgate()
{
	cout << "ScavTrap is now in gatekeeper mode" << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap destructor" << endl;
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
// 	cout << "ScavTrap " << name << " has taken " << amount << " damage." << endl;
// 	hp -= amount;
// }

// void ScavTrap::beRepaired(unsigned int amount)
// {
// 	cout << "ScavTrap " << name << " has repaired itself, gaining " << amount << " hit points." << endl;
// 	hp += amount;
// 	ep -= 1;
// }