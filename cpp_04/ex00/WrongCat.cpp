/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:18 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:19 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("wrongCat") {
  std::cout << "Default constructor for WrongCat\n";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
  std::cout << "Copy constructor for WrongCat\n";
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  std::cout << "Assignment operator for WrongCat\n";
  if (this == &rhs)
    return *this;
  WrongAnimal::operator=(rhs);
  return *this;
}

WrongCat::~WrongCat() { std::cout << "Default destructor for WrongCat\n"; }

void WrongCat::makeSound() const { std::cout << "Meow\n"; }
