/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:34 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point::~Point() {}

const Fixed &Point::getX() const { return (this->_x); }

const Fixed &Point::getY() const { return (this->_y); }

std::ostream &operator<<(std::ostream &o, const Point &rhs) {
  o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
  return o;
}
