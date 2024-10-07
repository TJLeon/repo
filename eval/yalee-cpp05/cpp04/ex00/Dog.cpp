#include "Dog.hpp"

Dog::Dog(): Animal()
{
    cout << "defaule doggo constructor" << endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& dog): Animal(dog)
{
    cout << "doggo copy constructor" << endl;
    *this = dog;
}

Dog &Dog::operator = (const Dog& dog)
{
    cout << "doggo copy constructor" << endl;
    if (this == &dog)
        return (*this);
    this->type = "Dog";
    return (*this);
}

Dog::~Dog()
{
    cout << "kill dog" << endl;
}

void Dog::makeSound(void)const
{
    cout << "yap yap yap" << endl;
}