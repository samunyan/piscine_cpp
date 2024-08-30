/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:38:42 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/01 16:38:43 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &src);
  FragTrap &operator=(const FragTrap &rhs);
  ~FragTrap();
  virtual void attack(const std::string &name);
  void highFivesGuys();

private:
  FragTrap();
};

std::ostream &operator<<(std::ostream &o, const FragTrap &rhs);

#endif
