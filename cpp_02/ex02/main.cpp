/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:31 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:22:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
  {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl << std::endl;
  }
  {
    Fixed a(10);
    const Fixed b(3);
    Fixed c(3);
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << std::boolalpha << (a > b) << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (c == b) << std::endl;
    std::cout << (c != b) << std::endl;
    std::cout << (c >= b) << std::endl;
    std::cout << (c <= b) << std::endl;
    std::cout << std::noboolalpha;
  }

  return 0;
}