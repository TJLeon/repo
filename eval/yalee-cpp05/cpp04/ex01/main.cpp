#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal* animals[100];

	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Dog();
		Animal j = *animals[i];
		cout << animals[i] << "\n";
		cout << &j << "\n";
	}	

	for (int i = 50; i < 100; i++)
	{
		animals[i] = new Cat();
		Animal j = *animals[i];
		cout << animals[i] << "\n";
		cout << &j << "\n";
	}

	for (int i = 0; i < 100; i++)
		delete animals[i];

	return 0;
}