#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

using namespace std;

class ClapTrap{
private:
    string name;
    int hp;
    int ep;
    int atk;
public:
    ClapTrap();
    ClapTrap(string name);
    ~ClapTrap();
    void attack(const string& target);
    void takeDamage(unsigned int amont);
    void beRepaired(unsigned int amount);
    string getName();
    int getHp();
    int getEp();
    int getAtk();
};
#endif