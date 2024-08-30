/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:38:39 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/01 16:38:40 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "Param constructor for Fragtrap " + this->_name + '\n';
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
  std::cout << "Copy constructor for Fragtrap " + this->_name + '\n';
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "Default destructor for Fragtrap " + this->_name + '\n';
}

void FragTrap::attack(const std::string &target) {
  if (!this->_hitPoints) {
    std::cout << "FragTrap " + this->_name +
                     " can't attack, is dead (no hit points left). \n";
  } else if (!this->_energyPoints) {
    std::cout << "FragTrap " + this->_name +
                     " can't attack (no energy points left).\n";
  } else {
    std::cout << "FragTrap " + this->_name + " attacks " + target + ", causing "
              << this->_attackDamage << " point of damage.\n";
    this->_energyPoints--;
  }
}

void FragTrap::highFivesGuys() {
  std::cout << this->_name + ": High fives, guys\n";
}

std::ostream &operator<<(std::ostream &o, const FragTrap &rhs) {
  std::cout << "ScavTrap " + rhs.getName()
            << "\nHit points : " << rhs.getHitPoints()
            << "\nEnergy points : " << rhs.getEnergyPoints()
            << "\nAttack damage : " << rhs.getAttackDamage() << std::endl;
  return o;
}