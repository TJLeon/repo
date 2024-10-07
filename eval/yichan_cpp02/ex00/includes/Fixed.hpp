/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:58:01 by yichan            #+#    #+#             */
/*   Updated: 2024/04/06 23:00:33 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FIXED_HPP
# define    FIXED_HPP

# include<iostream>

class Fixed
{
	private:
		int 				m_value;
		static const int	m_exponential = 8;

	public:
		Fixed();
		Fixed(const Fixed &other); //copy constructor usage; // should be const
		Fixed &operator = (const Fixed &other);
		~Fixed();

		int		getRawBits( void ) const;					//getter
		void	setRawBits( int const raw );			//setter

};

#endif
