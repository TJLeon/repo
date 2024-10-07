#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <exception>
#include <iterator>

class ContainerFullException : public std::exception
{
public:
    const char* what() const throw();
};

class NoSpanException : public std::exception
{
public:
    const char* what() const throw();
};

class Span
{
private:
    unsigned int size;
    std::list<int> list;
public:
    Span(const unsigned int n);
    Span(const Span &span);
    Span& operator=(const Span &span);
    ~Span();
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void printList();
};

std::ostream& operator<<(std::ostream &out, const std::list<int> &list);

#endif