/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:19:59 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:00 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name) { this->_announce(); }

Zombie::~Zombie() { std::cout << this->_name << " is dead." << std::endl; }

void Zombie::_announce() {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
