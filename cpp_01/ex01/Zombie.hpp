/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:20 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:21 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
  Zombie();
  Zombie(const std::string &name);
  ~Zombie();

private:
  std::string _name;
  void _announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif
