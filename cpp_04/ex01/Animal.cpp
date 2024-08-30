/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:52:03 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/12 18:52:04 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("<undefined type>") {
  std::cout << "Default constructor for Animal\n";
}

Animal::Animal(const std::string &type) : _type(type) {
  std::cout << "Param constructor for Animal\n";
}

Animal::Animal(const Animal &src) : _type(src._type) {
  std::cout << "Copy constructor for Animal\n";
}

Animal &Animal::operator=(const Animal &rhs) {
  std::cout << "Assignment operator for Animal\n";
  if (this == &rhs)
    return *this;
  this->_type = rhs._type;
  return *this;
}

Animal::~Animal() { std::cout << "Default destructor for Animal\n"; }

void Animal::makeSound() const { std::cout << "<undefined sound>\n"; }

std::string Animal::getType() const { return this->_type; }

std::ostream &operator<<(std::ostream &o, const Animal &rhs) {
  o << "Animal with type " + rhs.getType() + '\n';
  return o;
}
