/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:26 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:27 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.hpp"

bool getInput(const std::string &question, int field_type, std::string &input) {
  while (true) {

    input.clear();

    std::cout << BLUE << question << ": " << RESET;
    std::getline(std::cin, input);

    if (std::cin.eof())
      return (false);
    if (input.empty())
      std::cout << RED << "This field is required. Try again." << RESET
                << std::endl;
    else if (field_type == numeric &&
             input.find_first_not_of("0123456789") != std::string::npos)
      std::cout << RED << "Not a valid number. Try again." << RESET
                << std::endl;
    else
      return (true);
  }
}
