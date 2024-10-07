#include "contact.hpp"

class Phonebook{
public:
	Phonebook();
	~Phonebook();
	void add_contacts();
	void search_and_print_contact();
	void print_contacts();
	std::string truncate_str(const std::string& str);
private:
	Contact contacts[8];
	int index;
};