#include "Span.hpp"

Span::Span(unsigned int n) : size(n) 
{

}

Span::Span(const Span &span) : size(span.size), list(span.list) 
{

}

Span& Span::operator=(const Span &span)
{
    if (this != &span)
    {
        size = span.size;
        list = span.list;
    }
    return *this;
}

Span::~Span() 
{

}

void Span::addNumber(int n)
{
    if (static_cast<unsigned int>(list.size()) >= this->size)
    {
        throw ContainerFullException();
    }
    list.push_back(n);
}

int Span::shortestSpan()
{
    if (static_cast<unsigned int>(list.size()) < 2)
    {
        throw ContainerFullException();
    }
    list.sort();
    int min = *list.begin();
    list.pop_front();
    std::list<int>::iterator it = list.begin();
    for(it = list.begin(); it != list.end(); it++)
    {
        if ((*it - min) > 0)
            return (*it - min);  
    }
    throw NoSpanException();
}

int Span::longestSpan()
{
    if (static_cast<int>(list.size()) < 2)
    {
        throw ContainerFullException();
    }
    return (*std::max_element(list.begin(), list.end()) - *std::min_element(list.begin(), list.end()));
}

const char* ContainerFullException::what() const throw()
{
    return "Container is full";
}

const char* NoSpanException::what() const throw()
{
    return "No span to find";
}

void Span::printList()
{
    std::cout << "List: ";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
