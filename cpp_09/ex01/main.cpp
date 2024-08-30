/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:14:36 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/02 15:14:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[]) {
  try {
    if (ac != 2)
      throw std::runtime_error(
          "usage: ./RPN \"<inverted Polish mathematical expression>\"");
    RPN rpn(av[1]);
    std::cout << rpn.getResult() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}