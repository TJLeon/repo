#include <iostream>
#include <string>
#include <iomanip>

class Contact{
public:
	Contact();
	~Contact();
	void set_first_name(std::string newStr);
	void set_last_name(std::string newStr);
	void set_nickname(std::string newStr);
	void set_phone_number(std::string newStr);
	void set_darkest_secret(std::string newStr);

	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();				
	std::string get_phone_number();
	std::string get_darkest_secret();
private:
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string phone_number;
	std::string darkest_secret;
};
