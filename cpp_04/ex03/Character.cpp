/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:01:20 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 13:01:21 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _slots(), _unequipped(), _name("<name undefined>") {}

Character::Character(const std::string &name)
    : _slots(), _unequipped(), _name(name) {}

Character::Character(const Character &src) : _name(src._name) {
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
    this->_slots[i] = (src._slots[i]) ? src._slots[i]->clone() : NULL;
  }
  for (int i(0); i < 20; ++i) {
    delete this->_unequipped[i];
    this->_unequipped[i] =
        (src._unequipped[i]) ? src._unequipped[i]->clone() : NULL;
  }
}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;
  this->_name = rhs._name;
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
    this->_slots[i] = (rhs._slots[i]) ? rhs._slots[i]->clone() : NULL;
  }
  for (int i(0); i < 20; ++i) {
    delete this->_unequipped[i];
    this->_unequipped[i] =
        (rhs._unequipped[i]) ? rhs._unequipped[i]->clone() : NULL;
  }
  return *this;
}

Character::~Character() {
  for (int i(0); i < 4; ++i) {
    delete this->_slots[i];
  }
  for (int i(0); i < 20; ++i) {
    delete this->_unequipped[i];
  }
}

const AMateria *Character::getMateriaAt(int idx) const {
  if (idx < 0 || idx > 3)
    return NULL;
  return this->_slots[idx];
}

const std::string &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m) {
  for (int i(0); i < 4; ++i) {
    if (!this->_slots[i]) {
      this->_slots[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3 || !this->_slots[idx])
    return;
  for (int i(0); i < 20; ++i) {
    if (!this->_unequipped[i]) {
      this->_unequipped[i] = this->_slots[idx];
      this->_slots[idx] = NULL;
      break;
    }
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3 || !this->_slots[idx])
    return;
  this->_slots[idx]->use(target);
}
