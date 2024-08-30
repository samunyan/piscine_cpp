/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:02 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:03 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(const std::string &name);
  ~Zombie();

private:
  std::string _name;
  void _announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
