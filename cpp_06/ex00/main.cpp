/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:20:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/15 14:20:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.hpp"

int main(int ac, char *av[]) {
  if (ac != 2) {
    std::cerr << FG_RED "Error: wrong number of arguments" << RESET_ALL
              << std::endl;
    return 1;
  }
  try {
    ScalarConverter::convert((av[1]));
    return 0;
  } catch (std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
    return 1;
  }
}