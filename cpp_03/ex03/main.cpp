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
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  //  ClapTrap gigi("Gigi");
  //  ClapTrap stu("Stu");
  //
  //  gigi.attack(stu.getName());
  //  stu.takeDamage(gigi.getAttackDamage());
  //  gigi.attack(stu.getName());
  //  stu.takeDamage(gigi.getAttackDamage());
  //  stu.beRepaired(gigi.getAttackDamage());
  //
  //  ScavTrap poe("Poe");
  //  poe.attack(gigi.getName());
  //  gigi.takeDamage(poe.getAttackDamage());
  //  poe.guardGate();
  //  gigi.attack(poe.getName());
  //  poe.takeDamage(gigi.getAttackDamage());
  //  poe.beRepaired(gigi.getAttackDamage());
  //
  //    FragTrap frag("Frag");
  //    frag.attack(frag.getName());
  //  poe.takeDamage(frag.getAttackDamage());

  //  DiamondTrap diamond("Diamond");
  //  std::cout << diamond;
  //  DiamondTrap two(diamond);
  //  two.whoAmI();

  ClapTrap clap("clap");
  std::cout << clap;

  FragTrap frag("frag");
  std::cout << frag;
  frag.attack(clap.getName());

  ScavTrap scav("scav");
  std::cout << scav;

  DiamondTrap diamond("Diamond");
  std::cout << diamond;

  DiamondTrap cop(diamond);
  std::cout << cop;
  cop.whoAmI();
  cop.attack("test");
  cop.highFivesGuys();
  cop.guardGate();
  return 0;
}