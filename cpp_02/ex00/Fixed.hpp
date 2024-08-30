/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:00 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:22:01 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &src);
  Fixed &operator=(const Fixed &rhs);
  ~Fixed();
  int getRawBits() const;
  void setRawBits(const int rawBits);

private:
  int _rawBits;
  static const int _nFractBits = 8;
};

#endif
