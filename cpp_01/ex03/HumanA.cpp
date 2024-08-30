/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:34 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:35 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const {
  std::cout << this->_name << " attacks with " << this->_weapon.getType()
            << std::endl;
}
