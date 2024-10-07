#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <numeric>

class Span{
	private:
		unsigned int		size;
		std::vector<int>	numbers;
	public:
		Span(const int size = 0);
		Span(const Span &src);
		~Span(void);

		//methods
		void showNumber();
		void addNumber(const int num); 
		long shortestSpan()const;
		long longestSpan()const;

		//exceptions
		class numFullException : public std::exception
		{
			public:
				virtual const char *what () const throw();
		};

		class SpanNotFoundException:public std::exception
		{	public:virtual const char *what() const throw();};
		

		//operator
		Span &operator = (const Span &src);
		
};


#endif