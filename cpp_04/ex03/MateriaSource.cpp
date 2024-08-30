/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:47 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:48 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _slots() {}

MateriaSource::MateriaSource(const MateriaSource &src) {
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
    this->_slots[i] = (src._slots[i]) ? src._slots[i]->clone() : NULL;
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this == &rhs)
    return *this;
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
    this->_slots[i] = (rhs._slots[i]) ? rhs._slots[i]->clone() : NULL;
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i(0); i < 4; ++i) {
    if (!this->_slots[i]) {
      this->_slots[i] = m;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i(0); i < 4; ++i) {
    if (this->_slots[i] && (this->_slots[i]->getType() == type)) {
      return ((this->_slots[i])->clone());
    }
  }
  return NULL;
}
