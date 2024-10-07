#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include "Color.hpp"
# include "Test.hpp"

template <typename T>
class Array{
	private:
		T *m_array;
		unsigned len;

	public:
		Array();
		Array(unsigned int);
		Array(Array const &src);
		~Array();

		const T *getArray(void) const;

		Array &operator = (Array const &src);
		T &operator [] (int i);

		unsigned int size() const;

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"


#endif