/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:13 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:22:14 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const int i);
  Fixed(const float f);
  Fixed(const Fixed &src);
  ~Fixed();
  Fixed &operator=(const Fixed &rhs);
  int getRawBits() const;
  void setRawBits(const int rawBits);
  float toFloat() const;
  int toInt() const;

private:
  int _rawBits;
  static const int _nFractBits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif
