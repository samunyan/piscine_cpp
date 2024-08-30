/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:07 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:16 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed areaTriangle(Point const a, Point const b, Point const c) {
  Point vecAB((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
  Point vecAC((c.getX() - a.getX()).toFloat(), (c.getY() - a.getY()).toFloat());
  Fixed res = (vecAB.getX() * vecAC.getY() - vecAC.getX() * vecAB.getY()) / 2;
  if (res < 0)
    res = Fixed(0) - res;
  return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed areaOfTriangle = areaTriangle(a, b, c);
  Fixed areaSum = areaTriangle(a, b, point) + areaTriangle(a, c, point) +
                  areaTriangle(b, c, point);
  return (areaOfTriangle == areaSum);
}
