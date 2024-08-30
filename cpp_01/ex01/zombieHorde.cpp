/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:25 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:26 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {

  Zombie *arr(new Zombie[N]);

  for (int i(0); i < N; ++i) {
    arr[i] = Zombie(name);
  }
  return arr;
}
