/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:12 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:13 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("<undefined type>") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &src) : _type(src._type) {}

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this == &rhs)
    return *this;
  this->_type = rhs._type;
  return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter &target) { (void)target; }
