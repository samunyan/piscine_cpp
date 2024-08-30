/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:27:03 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/30 16:27:04 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _hitPoints(_defaultHitPoints), _energyPoints(_defaultEnergyPoints),
      _attackDamage(_defaultAttackDamage) {
  std::cout << "Default constructor for Claptrap\n";
}

ClapTrap::ClapTrap(const std::string &name, const int hitPoints,
                   const int energyPoints, const int attackDamage)
    : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints),
      _attackDamage(attackDamage) {
  std::cout << "Param constructor for Claptrap " + this->_name + '\n';
}

ClapTrap::ClapTrap(const ClapTrap &src)
    : _name(src._name), _hitPoints(src._hitPoints),
      _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
  std::cout << "Copy constructor for Claptrap " + this->_name + '\n';
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  if (this == &rhs)
    return *this;
  this->_name = rhs._name;
  this->_hitPoints = rhs._hitPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "Default destructor for Claptrap " + this->_name + '\n';
}

void ClapTrap::attack(const std::string &target) {
  if (!this->_hitPoints) {
    std::cout << "ClapTrap " + this->_name +
                     " can't attack, is dead (no hit points left). \n";
  } else if (!this->_energyPoints) {
    std::cout << "ClapTrap " + this->_name +
                     " can't attack (no energy points left).\n";
  } else {
    std::cout << "ClapTrap " + this->_name + " attacks " + target + ", causing "
              << this->_attackDamage << " point of damage.\n";
    this->_energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!this->_hitPoints) {
    std::cout << this->_name +
                     " can't take damage, is dead (no hit points left). \n";
  } else {
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
      this->_hitPoints = 0;
    std::cout << this->_name + " takes " << amount << " points of damage. \n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->_hitPoints) {
    std::cout << this->_name +
                     " can't be repaired, is dead (no hit points left). \n";
  } else if (!this->_energyPoints) {
    std::cout << this->_name + " can't be repaired (no energy points left).\n";
  } else {
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << this->_name + " is repaired for " << amount
              << " hit points.\n";
  }
}

std::string ClapTrap::getName() const { return this->_name; }

int ClapTrap::getHitPoints() const { return this->_hitPoints; }

int ClapTrap::getEnergyPoints() const { return this->_energyPoints; }

int ClapTrap::getAttackDamage() const { return this->_attackDamage; }

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs) {
  std::cout << "ClapTrap " + rhs.getName()
            << "\nHit points : " << rhs.getHitPoints()
            << "\nEnergy points : " << rhs.getEnergyPoints()
            << "\nAttack damage : " << rhs.getAttackDamage() << std::endl;
  return o;
}
