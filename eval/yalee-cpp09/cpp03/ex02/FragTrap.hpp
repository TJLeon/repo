#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

using	namespace std;

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator = (const FragTrap &fragtrap);
		~FragTrap();

		void	attack(const string &target);
		void	highFivesGuys(void);
};

#endif