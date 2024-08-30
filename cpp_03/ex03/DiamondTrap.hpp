/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:48:54 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/01 21:48:55 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &src);
  DiamondTrap &operator=(const DiamondTrap &rhs);
  ~DiamondTrap();
  virtual void attack(const std::string &target);
  void whoAmI();
  std::string getName() const;

private:
  DiamondTrap();
  std::string _name;
};

std::ostream &operator<<(std::ostream &o, const DiamondTrap &rhs);

#endif
