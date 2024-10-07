#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator = (const Cat &cat);
		~Cat();

		void	makeSound(void) const;
	private:
		Brain* brain;
};


#endif