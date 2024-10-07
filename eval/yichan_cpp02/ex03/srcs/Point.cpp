/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:34:31 by yichan            #+#    #+#             */
/*   Updated: 2023/09/08 16:07:08 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():m_x(0), m_y(0){};
Point::Point(const float x, const float y) : m_x(x), m_y(y) {};
// Point::Point(const float m_x, const float m_y)
// {
// 	this->m_x = Fixed(m_x);
// 	this->m_y = Fixed(m_y);
// };

// Point::Point(const Point &other)				//headacge
// {
// // 	if (this == &other)
// // 		return ;
// // 	*this = static_cast <const Point>(other);
// 	* this = Point(other);
// }

Point::~Point(){
	// std::cout << "[Point] destructor was being called" << std::endl;

};

Point::Point(const Point &other) : m_x(other.m_x), m_y(other.m_y)
{
    // std::cout << "Copy constructor called" << std::endl;
    // *this = other
}

Point	&Point::operator = (const Point &other)
{
	// this->m_x = other.m_x;
	// this->m_y = other.m_y;
	// if (this == &other)
	// 	return (*this);
	// *this = Point(other);
	return (*this);
	(void)other;
}

bool	Point::operator==(const Point &other) const
{
	return m_x == other.m_x && m_y == other.m_y;
}

Fixed	Point::getX() const
{
	return m_x;
}

Fixed	Point::getY() const
{
	return m_y;
}

std::ostream&	operator << (std::ostream &out, const Point &other)
{
	out << "m_x: " << other.getX() << " m_y: " << other.getY();
	return out;
}