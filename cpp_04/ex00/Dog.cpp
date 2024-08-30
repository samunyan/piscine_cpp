/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:06 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:07 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog") { std::cout << "Default constructor for Dog\n"; }

Dog::Dog(const Dog &src) : Animal(src) {
  std::cout << "Copy constructor for Dog\n";
}

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Assignment operator for Dog\n";
  if (this == &rhs)
    return *this;
  Animal::operator=(rhs);
  return *this;
}

Dog::~Dog() { std::cout << "Default destructor for Dog\n"; }

void Dog::makeSound() const { std::cout << "Woof\n"; }
