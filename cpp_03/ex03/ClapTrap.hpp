/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:27:05 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/30 16:27:06 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap(const std::string &name, const int hitPoints = _defaultHitPoints,
           const int energyPoints = _defaultEnergyPoints,
           const int attackDamage = _defaultAttackDamage);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap();
  virtual void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  virtual std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

protected:
  ClapTrap();
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
  static const int _defaultHitPoints = 10;
  static const int _defaultEnergyPoints = 10;
  static const int _defaultAttackDamage = 0;
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs);

#endif