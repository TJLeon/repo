#include "phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string input;
	Phonebook phonebook;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
        for (std::string::size_type i = 0; i < input.length(); ++i)
        {
            input[i] = std::toupper(input[i]);
        }
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phonebook.add_contacts();
		else if (input == "SEARCH")
			phonebook.search_and_print_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
}
