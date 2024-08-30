/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:05:08 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 11:05:10 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"
#include "colors.hpp"
#include "whatever.hpp"

int main() {
  std::cout << BG_BLUE << "Integers" << RESET_ALL << std::endl;
  int a = 2;
  int b = 3;
  std::cout << "Before swap: ";
  std::cout << "a = " << a << ", b = " << b << std::endl;
  ::swap(a, b);
  std::cout << "After swap: ";
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::cout << BG_BLUE << "Strings" << RESET_ALL << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  std::cout << "Before swap: ";
  std::cout << "c = " << c << ", d = " << d << std::endl;
  ::swap(c, d);
  std::cout << "After swap: ";
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  std::cout << BG_BLUE << "Pair class" << RESET_ALL << std::endl;
  Pair e(1, 2);
  Pair f(3, 4);
  std::cout << "Before swap: ";
  std::cout << "e = " << e << ", f = " << f << std::endl;
  ::swap(e, f);
  std::cout << "After swap: ";
  std::cout << "e = " << e << ", f = " << f << std::endl;
  std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
  std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

  return 0;
}
