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
#include "iter.hpp"
#include <iostream>

int main() {
  int a[3] = {1, 2, 3};
  ::iter(a, 3, print<const int>);
  std::cout << std::endl;
  ::iter(a, 3, add<int>);
  ::iter(a, 3, print<const int>);
  std::cout << std::endl;

  char b[3] = {'a', 'b', 'c'};
  ::iter(b, 3, print<const char>);
  std::cout << std::endl;
  ::iter(b, 3, add<char>);
  ::iter(b, 3, print<const char>);
  std::cout << std::endl;

  Pair c[3];
  ::iter(c, 3, print<Pair>);
  std::cout << std::endl;
  ::iter(c, 3, add<Pair>);
  ::iter(c, 3, print<Pair>);
  std::cout << std::endl;

  return 0;
}
