/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:25 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:26 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria(src) {}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;
  this->AMateria::operator=(rhs);
  return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
