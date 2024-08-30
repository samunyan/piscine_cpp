/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:37 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:38 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
public:
  HumanA(const std::string &name, const Weapon &weapon);
  ~HumanA();
  void attack() const;

private:
  const std::string _name;
  const Weapon &_weapon;
};

#endif
