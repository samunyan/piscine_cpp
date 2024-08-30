/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:32 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria(src) {}

Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs)
    return *this;
  this->AMateria::operator=(rhs);
  return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " + target.getName() + " *\n";
}
