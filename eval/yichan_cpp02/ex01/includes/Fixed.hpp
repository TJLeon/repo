/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:36:00 by yichan            #+#    #+#             */
/*   Updated: 2023/07/30 23:42:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>


// reference return operator overload is necessary if the operator result is lvalue andd need a memory location.

class Fixed
{
	private:
		int 				m_value;
		static const int	m_exponential = 8;

	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float integer);
		Fixed(const Fixed &other); //copy constructor usage; // should be const
		Fixed &operator = (const Fixed &other);
		~Fixed();

		int		getRawBits( void ) const;					//getter
		void	setRawBits( int const raw );				//setter
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &other);

#endif
