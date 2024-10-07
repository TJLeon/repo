#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	cout << "Default brain constructor" << endl;
}

Brain::Brain(const Brain& brain)
{
	cout << "Copy brain constructor" << endl;
	*this = brain;
}

Brain &Brain::operator = (const Brain &brain)
{
	cout << "Brain Copy assignment operator " << endl;
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain destructor" << endl;
}