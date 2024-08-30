/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:16:31 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/25 01:16:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"

Pair::Pair() : _x(0), _y(1) {}

Pair::Pair(int x, int y) : _x(x), _y(y) {}

Pair::Pair(const Pair &src) : _x(src._x), _y(src._y) {}

Pair &Pair::operator=(const Pair &rhs) {
  if (this == &rhs)
    return *this;
  this->_x = rhs._x;
  this->_y = rhs._y;
  return *this;
}

int Pair::getX() const { return this->_x; }

int Pair::getY() const { return this->_y; }

void Pair::setX(int x) { this->_x = x; }

void Pair::setY(int y) { this->_y = y; }

Pair::~Pair() {}

std::ostream &operator<<(std::ostream &o, const Pair &rhs) {
  o << "( " << rhs.getX() << ", " << rhs.getY() << " )";
  return (o);
}
