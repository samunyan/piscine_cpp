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
  ClapTrap(const std::string &name, const int hitPoints = 10,
           const int energyPoints = 10, const int attackDamage = 0);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap();
  virtual void attack(const std::string &name);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

private:
  ClapTrap();
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs);

#endif