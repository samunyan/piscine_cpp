/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:25 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:22:26 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _rawBits(i << Fixed::_nFractBits) {
  // std::cout << "Parameterized int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
    : _rawBits((int)roundf((f * (1 << Fixed::_nFractBits)))) {
  // std::cout << "Parameterized float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _rawBits(src._rawBits) {
  // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this == &rhs)
    return *this;
  this->_rawBits = rhs._rawBits;
  return *this;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;
}

void Fixed::setRawBits(const int raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat() const {
  return (float)(this->_rawBits) / (1 << Fixed::_nFractBits);
}

int Fixed::toInt() const { return this->_rawBits >> Fixed::_nFractBits; }

bool Fixed::operator>(const Fixed &rhs) const {
  return this->_rawBits > rhs._rawBits;
}

bool Fixed::operator<(const Fixed &rhs) const {
  return !(operator>(rhs) || operator==(rhs));
}

bool Fixed::operator>=(const Fixed &rhs) const { return !(operator<(rhs)); }

bool Fixed::operator<=(const Fixed &rhs) const { return !(operator>(rhs)); }

bool Fixed::operator==(const Fixed &rhs) const {
  return this->_rawBits == rhs._rawBits;
}

bool Fixed::operator!=(const Fixed &rhs) const { return !(operator==(rhs)); }

Fixed Fixed::operator+(const Fixed &b) const {
  return Fixed(this->toFloat() + b.toFloat());
}

Fixed Fixed::operator-(const Fixed &b) const {
  return Fixed(this->toFloat() - b.toFloat());
}

Fixed Fixed::operator*(const Fixed &b) const {
  return Fixed(this->toFloat() * b.toFloat());
}

Fixed Fixed::operator/(const Fixed &b) const {
  return Fixed(this->toFloat() / b.toFloat());
}

Fixed &Fixed::operator++() {
  ++this->_rawBits;
  return *this;
}

Fixed &Fixed::operator--() {
  --this->_rawBits;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b)
    return a;
  return b;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
  o << rhs.toFloat();
  return o;
}
