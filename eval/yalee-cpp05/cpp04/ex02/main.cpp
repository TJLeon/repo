#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	Animal* j = new Dog();
	Animal* i = new Cat();

	delete j;
	delete i;

	Animal* animals[100];

	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Dog();
		Dog *j = reinterpret_cast<Dog *>(animals[i]);
		Dog k = *j;
		cout << animals[i] << "\n";
		cout << &k << "\n";
	}

	for (int i = 50; i < 100; i++)
	{
		animals[i] = new Cat();
		Cat *j = reinterpret_cast<Cat *>(animals[i]);
		Cat k = *j;
		cout << animals[i] << "\n";
		cout << &k << "\n";
	}

	for (int i = 0; i < 100; i++)
		delete animals[i];

	return 0;
}