/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:27 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  const Point a(0, 0);
  const Point b(10, 10);
  const Point c(10, 0);

  std::cout << "Triangle is defined by A" << a << ", B" << b << ", C" << c
            << std::endl;

  Point point(50, 50);
  std::cout << "Point" << point;

  if (bsp(a, b, c, point))
    std::cout << " lies in triangle" << std::endl;
  else
    std::cout << " lies not in triangle" << std::endl;

  return 0;
}
