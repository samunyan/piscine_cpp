/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:19:53 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:19:54 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  Zombie jim("jim");
  randomChump("rob");
  Zombie *clark = newZombie("clark");
  delete clark;
  return 0;
}
