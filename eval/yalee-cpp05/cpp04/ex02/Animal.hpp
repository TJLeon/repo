#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

using namespace std;

class Animal{
protected:
    string type;
    Animal();
    Animal(string type);
    Animal(const Animal& animal);
public:
   // Animal();
   // Animal(string type);
   // Animal(const Animal& animal);
    Animal& operator = (const Animal& animal);
   // ~Animal();
    virtual ~Animal();
    string getType(void) const;
    virtual void makeSound(void) const;
};

#endif