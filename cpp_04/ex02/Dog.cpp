/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:20:21 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:20:22 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("dog"), _myBrain(new Brain()) {
  std::cout << "Default constructor for Dog\n";
}

Dog::Dog(const Dog &src) : AAnimal(src), _myBrain(new Brain(*src._myBrain)) {
  std::cout << "Copy constructor for Dog\n";
}

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Assignment operator for Dog\n";
  if (this == &rhs)
    return *this;
  AAnimal::operator=(rhs);
  *(this->_myBrain) = *rhs._myBrain;
  return *this;
}

Dog::~Dog() {
  std::cout << "Default destructor for Dog\n";
  delete this->_myBrain;
}

void Dog::makeSound() const { std::cout << "Woof\n"; }

const Brain *Dog::getBrain() const { return this->_myBrain; }
