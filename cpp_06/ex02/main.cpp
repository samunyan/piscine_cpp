/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:10 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/17 12:07:04 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>

Base *generate() {
  std::srand((std::time(nullptr)));
  int random = std::rand() % 3;
  switch (random) {
  case 0:
    std::cout << "Pointer to A generated" << std::endl;
    return new A;
  case 1:
    std::cout << "Pointer to B generated" << std::endl;
    return new B;
  case 2:
    std::cout << "Pointer to C generated" << std::endl;
    return new C;
  default:
    return nullptr;
  }
}

void identify(Base *p) {
  try {
    A *a = dynamic_cast<A *>(p);
    if (a == nullptr)
      throw std::bad_cast();
    std::cout << "Pointer to Base is of type A" << std::endl;
  } catch (std::exception &) {
    try {
      B *b = dynamic_cast<B *>(p);
      if (b == nullptr)
        throw std::bad_cast();
      std::cout << "Pointer to Base is of type B" << std::endl;
    } catch (std::exception &) {
      try {
        C *c = dynamic_cast<C *>(p);
        if (c == nullptr)
          throw std::bad_cast();
        std::cout << "Pointer to Base is of type C" << std::endl;
      } catch (std::exception &e) {
        throw;
      }
    }
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Reference to Base is of type A" << std::endl;
  } catch (std::exception &) {
    try {
      B &b = dynamic_cast<B &>(p);
      (void)b;
      std::cout << "Reference to Base is of type B" << std::endl;
    } catch (std::exception &) {
      try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Reference to Base is of type C" << std::endl;
      } catch (std::exception &e) {
        throw;
      }
    }
  }
}

int main() {
  Base *p;
  try {
    p = generate();
    Base &r(*p);
    identify(p);
    identify(r);
  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  delete p;
  return 0;
}