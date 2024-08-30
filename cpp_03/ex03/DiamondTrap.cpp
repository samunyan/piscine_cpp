/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:48:52 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/01 21:48:53 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name", FragTrap::_defaultHitPoints,
               ScavTrap::_defaultEnergyPoints, FragTrap::_defaultAttackDamage),
      FragTrap(name), ScavTrap(name), _name(name) {
  std::cout << "Param constructor for Diamondtrap " + this->_name + '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name) {
  std::cout << "Copy constructor for Diamondtrap " + this->_name + '\n';
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  this->_name = rhs._name;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "Default destructor for Diamondtrap " + this->_name + '\n';
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am ClapTrap " + ClapTrap::getName() + ". I am DiamondTrap " +
                   this->_name + "."
            << std::endl;
}

std::string DiamondTrap::getName() const { return this->_name; }

std::ostream &operator<<(std::ostream &o, const DiamondTrap &rhs) {
  std::cout << "DiamondTrap " + rhs.getName()
            << "\nHit points : " << rhs.getHitPoints()
            << "\nEnergy points : " << rhs.getEnergyPoints()
            << "\nAttack damage : " << rhs.getAttackDamage() << std::endl;
  return o;
}
