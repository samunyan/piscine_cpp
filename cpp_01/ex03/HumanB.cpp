/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:40 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
  if (this->_weapon == NULL) {
    std::cout << this->_name << " can't attack, has no weapon" << std::endl;
  } else {
    std::cout << this->_name << " attacks with " << this->_weapon->getType()
              << std::endl;
  }
}

void HumanB::setWeapon(const Weapon &weapon) { this->_weapon = &weapon; }