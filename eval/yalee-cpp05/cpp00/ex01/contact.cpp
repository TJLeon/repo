#include "contact.hpp"

void Contact::set_first_name(std::string newStr)
{	
	Contact::first_name = newStr;		
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_last_name(std::string newStr)
{	
	Contact::last_name = newStr;
}

void Contact::set_nickname(std::string newStr)		
{	
	Contact::nickname = newStr;			
}

void Contact::set_phone_number(std::string newStr)
{	
	Contact::phone_number = newStr;		
}

void Contact::set_darkest_secret(std::string newStr)	
{	
	Contact::darkest_secret = newStr;	
}

std::string Contact::get_first_name() 				
{ 	
	return Contact::first_name; 		
}

std::string Contact::get_last_name()					
{	
	return Contact::last_name;		
}

std::string Contact::get_nickname()					
{	
	return Contact::nickname;		
}

std::string Contact::get_phone_number()				
{	
	return Contact::phone_number;	
}

std::string Contact::get_darkest_secret()			
{	
	return Contact::darkest_secret;	
}