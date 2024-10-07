#include "Dog.hpp"

Dog::Dog(): Animal()
{
    cout << "defaule doggo constructor" << endl;
    this->type = "Dog";
    this->brain = new Brain();
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
    this->brain = new Brain();
	*(this->brain) = *(dog.brain);
    return (*this);
}

Dog::~Dog()
{
    cout << "kill dog" << endl;
    delete this->brain;
}

void Dog::makeSound(void)const
{
    cout << "yap yap yap" << endl;
}