/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:35 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
public:
  Point();
  Point(float x, float y);
  Point(const Point &src);
  ~Point();
  const Fixed &getX() const;
  const Fixed &getY() const;

private:
  const Fixed _x;
  const Fixed _y;
  Point &operator=(const Point &);
};

std::ostream &operator<<(std::ostream &, const Point &);

#endif
