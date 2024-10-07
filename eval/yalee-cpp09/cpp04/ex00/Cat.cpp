#include "Cat.hpp"

Cat::Cat(): Animal()
{
    cout << "cat default constructor" << endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& cat): Animal(cat)
{
    cout << "cat constructor" << endl;
    *this = cat;
}

Cat &Cat::operator = (const Cat& cat)
{
    cout << "cat copy constructor" << endl;
    if (this == &cat)
        return (*this);
    this->type = "Cat";
    return (*this);
}

Cat::~Cat()
{
    cout << "cat destrutor" << endl;
}

void Cat::makeSound(void)const
{
    cout << "meow meow N@#ga!" << endl;
}