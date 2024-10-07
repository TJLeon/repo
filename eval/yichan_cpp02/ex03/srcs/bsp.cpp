/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:16:00 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 11:31:33 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const p1, Point const p2, Point const p3)
{
	return Fixed((float)fabs((p1.getX()*(p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY()) + p3.getX()*(p1.getY()-p2.getY())).toFloat()/2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a1 = area(point, a, b);
	Fixed a2 = area(point, b, c);
	Fixed a3 = area(point, c, a);
	Fixed total = area(a, b, c);

	return (a1 + a2 + a3 == total && a1 != 0 && a2 != 0 && a3 != 0);
}
