#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

using namespace std;

class Animal{
protected:
   // Animal();
    //Animal(string type);
   // Animal(const Animal& animal);
    string type;
public:
    Animal();
    Animal(string type);
    Animal(const Animal& animal);
    Animal& operator = (const Animal& animal);
   // ~Animal();
    virtual ~Animal();
    string getType(void) const;
    virtual void makeSound(void) const;
};

#endif