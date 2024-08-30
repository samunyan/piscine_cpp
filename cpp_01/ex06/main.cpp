/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:19 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:21:20 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int main(int ac, char *av[]) {

  if (ac != 2) {
    std::cout << "Wrong number of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  Harl test;
  test.complain(av[1]);

  return EXIT_SUCCESS;
}
