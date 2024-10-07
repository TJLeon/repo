#include "Span.hpp"

Span::Span(const int size):size(size)
{}

Span::Span(const Span & src)
{
	if (this == &src)
		return ;
	*this = src;
}

Span	&Span::operator = (const Span &src)
{
	this->size = src.size;
	this->numbers = src.numbers;
	return (*this);
}

Span::~Span(void){};

void	Span::addNumber(const int num)
{
	if (numbers.size() >= size)
		throw numFullException();
	else
		numbers.push_back(num);
}

void	Span::showNumber(void)
{
	// std::vector<int>::iterator itr = this->numbers.begin();
	for (std::vector<int>::iterator itr = this->numbers.begin();itr!=numbers.end();++itr)
		std::cout << "content in vector:\t" << *itr << std::endl;
}

long Span::longestSpan() const
{
	if (this->numbers.size() < 2)
		throw SpanNotFoundException();

	long min = *std::min_element(this->numbers.begin(), this->numbers.end());
	long max = *std::max_element(this->numbers.begin(), this->numbers.end());
	return (max - min);
}

long Span::shortestSpan() const
{
	std::vector<int> span(this->numbers.size());


	if (this->numbers.size() < 2)
		throw SpanNotFoundException();
	std::vector<int> sorted(this->numbers);
	std::sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), span.begin());
	std::vector<int>::iterator ret = std::min_element(span.begin(), span.end());
	return ret[0];
}

const char *Span::numFullException::what() const throw()
{
	return "The Volume already full";
}

const char*Span::SpanNotFoundException::what() const throw()
{
	return "The Span is too short";
}

