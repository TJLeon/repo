#include "Data.hpp"

Data::Data()
{

}

Data::~Data()
{

}

void Data::setName(string const name)
{
    this->name = name;
}

string Data::getName() const
{
    return this->name;
}