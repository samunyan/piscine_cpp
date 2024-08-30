/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:52:03 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/12 18:52:04 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("<undefined type>") {
  std::cout << "Default constructor for AAnimal\n";
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
  std::cout << "Param constructor for AAnimal\n";
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
  std::cout << "Copy constructor for AAnimal\n";
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
  std::cout << "Assignment operator for AAnimal\n";
  if (this == &rhs)
    return *this;
  this->_type = rhs._type;
  return *this;
}

AAnimal::~AAnimal() { std::cout << "Default destructor for AAnimal\n"; }

std::string AAnimal::getType() const { return this->_type; }

std::ostream &operator<<(std::ostream &o, const AAnimal &rhs) {
  o << "AAnimal with type " + rhs.getType() + '\n';
  return o;
}
