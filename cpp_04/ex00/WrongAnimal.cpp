/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:12 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:13 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("<undefined type>") {
  std::cout << "Default constructor for WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
  std::cout << "Param constructor for WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
  std::cout << "Copy constructor for WrongAnimal\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  if (this == &rhs)
    return *this;
  this->_type = rhs._type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "Default destructor for WrongAnimal\n";
}

void WrongAnimal::makeSound() const { std::cout << "<undefined sound>\n"; }

std::string WrongAnimal::getType() const { return this->_type; }

std::ostream &operator<<(std::ostream &o, const WrongAnimal &rhs) {
  o << "Animal with type " + rhs.getType() + '\n';
  return o;
}
