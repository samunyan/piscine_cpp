/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:59:51 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/31 15:59:52 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &src);
  ScavTrap &operator=(const ScavTrap &rhs);
  ~ScavTrap();
  virtual void attack(const std::string &name);
  void guardGate();

private:
  ScavTrap();
};

std::ostream &operator<<(std::ostream &o, const ScavTrap &rhs);

#endif