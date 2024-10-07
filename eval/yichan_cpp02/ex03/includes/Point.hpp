/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:47:47 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 11:30:59 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
		Fixed const	m_x;
		Fixed const	m_y;
		
	public:
		Point();
		Point(const Point &other);
		Point(const float x, const float y);
		~Point();

		Point &operator = (const Point &other);
		bool operator==(const Point &other) const;


		Fixed	getX() const;
		Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const P);
std::ostream&	operator << (std::ostream &out, const Point &other);
