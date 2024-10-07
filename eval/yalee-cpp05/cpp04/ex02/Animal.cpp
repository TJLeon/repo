#include "Animal.hpp"

Animal::Animal()
{
    cout << "default constructor" << endl;
    this->type = "the founding chad";
}

Animal::Animal(string type): type(type)
{
    cout << "animal string constructor" << endl;
}

Animal::Animal(const Animal& animal)
{
    cout << "Animal copy constructor" << endl;
    *this = animal;
}

Animal &Animal::operator = (const Animal& animal)
{
    if (this == &animal)
        return (*this);
    this->type = animal.type;
    return (*this);
}

Animal::~Animal()
{
    cout << "destructor for animal" << endl;
}

string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void)const
{
    cout << "default animal sound" << endl;
}