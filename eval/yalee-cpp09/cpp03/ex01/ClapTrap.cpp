#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    cout << "default constructor for claptrap" << endl;
}

ClapTrap::ClapTrap(string name)
{
    cout << "claptrap created name: " << name << endl;
    ClapTrap::name = name;
    ClapTrap::atk = 1;
    ClapTrap::ep = 10;
    ClapTrap::hp = 10;
}

ClapTrap::~ClapTrap()
{
    cout << "destructor for claptrap" << endl;
}

string ClapTrap::getName()
{
    return (ClapTrap::name);
}

int ClapTrap::getAtk()
{
    return (ClapTrap::atk);
}

int ClapTrap::getEp()
{
    return (ClapTrap::ep);
}

int ClapTrap::getHp()
{
    return (ClapTrap::hp);
}

void ClapTrap::attack(const string & target)
{
    if (ClapTrap::ep > 0)
    {
        cout << "ClapTrap " << ClapTrap::name << "attacks " << target << "causing " << atk << "points of damage!" << endl; 
        ClapTrap::ep --;
    }
    else
        cout << "no energy" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    ClapTrap::hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amont)
{
    if (ClapTrap::ep > 0)
    {
        cout << "ClapTrap " << ClapTrap::name << "healed for " << amont << endl;
        ClapTrap::hp += amont;
        ClapTrap::ep --;
    }
    else
        cout << "no energy" << endl;
}