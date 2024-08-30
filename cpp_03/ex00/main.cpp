/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:27:19 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/30 16:27:20 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap gigi("Gigi");
  ClapTrap stu("Stu");

  gigi.attack(stu.getName());
  stu.takeDamage(10);
  gigi.attack(stu.getName());
  stu.takeDamage(10);
  stu.beRepaired(10);
}