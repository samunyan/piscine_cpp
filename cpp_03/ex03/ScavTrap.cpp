/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:59:49 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/31 15:59:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "Default constructor for Scavtrap\n";
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name, _defaultHitPoints, _defaultEnergyPoints,
               _defaultAttackDamage) {
  std::cout << "Param constructor for Scavtrap " + this->_name + '\n';
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  std::cout << "Copy constructor for Scavtrap " + this->_name + '\n';
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "Default destructor for Scavtrap " + this->_name + '\n';
}

void ScavTrap::attack(const std::string &target) {
  if (!this->_hitPoints) {
    std::cout << "ScavTrap " + this->_name +
                     " can't attack, is dead (no hit points left). \n";
  } else if (!this->_energyPoints) {
    std::cout << "ScavTrap " + this->_name +
                     " can't attack (no energy points left).\n";
  } else {
    std::cout << "ScavTrap " + this->_name + " attacks " + target + ", causing "
              << this->_attackDamage << " point of damage.\n";
    this->_energyPoints--;
  }
}

void ScavTrap::guardGate() {
  std::cout << this->_name + " is now in Gate keeper mode\n";
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &rhs) {
  std::cout << "ScavTrap " + rhs.getName()
            << "\nHit points : " << rhs.getHitPoints()
            << "\nEnergy points : " << rhs.getEnergyPoints()
            << "\nAttack damage : " << rhs.getAttackDamage() << std::endl;
  return o;
}
