/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:36:00 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 11:34:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
	private:
		int 				m_value;
		static const int	m_exponential = 8;

	public:
		//Default Constructor
		Fixed();
		// Overload;
		Fixed(const int integer);
		Fixed(const float integer);
		// Copy constructor
		Fixed(const Fixed &other); //copy constructor usage; // should be const
		~Fixed();

		// Methods
		int		getRawBits( void ) const;					//getter
		void	setRawBits( int const raw );				//setter
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static	Fixed&		max(Fixed &a, Fixed &b);
		static	Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		

		Fixed	&operator = (const Fixed &other);
		
		bool	operator > (const Fixed &other) const;
		bool	operator < (const Fixed &other) const;
		bool	operator >= (const Fixed &other) const;
		bool	operator <= (const Fixed &other) const;
		bool	operator == (const Fixed &other) const;
		bool	operator != (const Fixed &other) const;
		
		Fixed operator + (const Fixed& other) const;
		Fixed operator - (const Fixed& other) const;
		Fixed operator * (const Fixed& other) const;
		Fixed operator / (const Fixed& other) const;



		
		Fixed	&operator ++ (void);			//return reference cauz in cpp pre-crement is lvalue n memory location is identifiable
		Fixed	&operator -- (void);		
		Fixed	operator ++	(int);				//post- marker int dummy
		Fixed	operator --	(int);
		
		
		
};

std::ostream &operator << (std::ostream &out, const Fixed &other);		//

#endif
