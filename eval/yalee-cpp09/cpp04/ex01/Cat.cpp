#include "Cat.hpp"

Cat::Cat(): Animal()
{
    cout << "cat default constructor" << endl;
    this->type = "Cat";
    this->brain = new Brain();
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
    this->brain = new Brain();
	*(this->brain) = *(cat.brain);
    return (*this);
}

Cat::~Cat()
{
    cout << "cat destrutor" << endl;
    delete this->brain;
}

void Cat::makeSound(void)const
{
    cout << "meow meow N@#ga!" << endl;
}