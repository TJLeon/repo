#include "phonebook.hpp"

Phonebook::Phonebook()
{
	Phonebook::index = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::add_contacts()
{
	std::string input;
	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "No one has an empty name! Try again, and be honest." << std::endl;
		else
		{
			Phonebook::contacts[Phonebook::index].set_first_name(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "No one has an empty name! Try again, and be honest." << std::endl;
		else
		{
			Phonebook::contacts[Phonebook::index].set_last_name(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "No one has an empty name! Try again, and be honest." << std::endl;
		else
		{
			Phonebook::contacts[Phonebook::index].set_nickname(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "No one has an empty phone number! Try again, and be honest." << std::endl;
		else
		{
			Phonebook::contacts[Phonebook::index].set_phone_number(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "No one has an empty secret! Try again, and be honest." << std::endl;
		else
		{
			Phonebook::contacts[Phonebook::index].set_darkest_secret(input);
			break;
		}
	}
	Phonebook::index++;
	if (Phonebook::index == 8)
		Phonebook::index = 0;
}

void Phonebook::print_contacts()
{
	std::cout << std::setw(12) << std::right << std::setfill(' ') << "index" << "|"
			  << std::setw(12) << std::right << std::setfill(' ') << "first name" << "|" 
			  << std::setw(12) << std::right << std::setfill(' ') << "last name" << "|"
			  << std::setw(12) << std::right << std::setfill(' ') << "nickname" << "|" << std::endl;
	int i = 0;
	while (Phonebook::contacts[i].get_first_name().empty() == false)
	{
		std::cout << std::setw(12) << std::right << std::setfill(' ') << i << "|"
				<< std::setw(12) << std::right << std::setfill(' ')
				<< truncate_str(Phonebook::contacts[i].get_first_name()) << "|"
				<< std::setw(12) << std::right << std::setfill(' ') 
				<< truncate_str(Phonebook::contacts[i].get_last_name()) << "|"
				<< std::setw(12) << std::right << std::setfill(' ') 
				<< truncate_str(Phonebook::contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
}

std::string Phonebook::truncate_str(const std::string& str)
{
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}

void Phonebook::search_and_print_contact()
{
	std::string number;
	Phonebook::print_contacts();
	while (true)
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, number);
		if (number.empty() || number.length() > 1 || number[0] < '0' || number[0] > '7' || Phonebook::contacts[number[0] - '0'].get_first_name().empty())
		{
			Phonebook::print_contacts();
			std::cout << "Invalid input!" << std::endl;
		}
		else
			break;
		
	}
	std::cout << "First name: " << Phonebook::contacts[number[0] - '0'].get_first_name() << std::endl;
	std::cout << "Last name: " << Phonebook::contacts[number[0] - '0'].get_last_name() << std::endl;
	std::cout << "Nickname: " << Phonebook::contacts[number[0] - '0'].get_nickname() << std::endl;
	std::cout << "Phone number: " << Phonebook::contacts[number[0] - '0'].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << Phonebook::contacts[number[0] - '0'].get_darkest_secret() << std::endl;
}