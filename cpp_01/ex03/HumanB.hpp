/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:42 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:43 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
public:
  HumanB(const std::string &name);
  ~HumanB();
  void attack() const;
  void setWeapon(const Weapon &weapon);

private:
  const std::string _name;
  const Weapon *_weapon;
};

#endif
