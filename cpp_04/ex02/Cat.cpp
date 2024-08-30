/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:20:15 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:20:17 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("cat"), _myBrain(new Brain()) {
  std::cout << "Default constructor for Cat\n";
}

Cat::Cat(const Cat &src) : AAnimal(src), _myBrain(new Brain(*src._myBrain)) {
  std::cout << "Copy constructor for Cat\n";
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Assignment operator for Cat\n";
  if (this == &rhs)
    return *this;
  this->AAnimal::operator=(rhs);
  *(this->_myBrain) = *rhs._myBrain;
  return *this;
}

Cat::~Cat() {
  std::cout << "Default destructor for Cat\n";
  delete this->_myBrain;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }

const Brain *Cat::getBrain() const { return this->_myBrain; }
