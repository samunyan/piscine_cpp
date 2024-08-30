/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:14 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:21:15 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  static const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i;

  for (i = 0; i < 4; i++) {
    if (level == levels[i]) {
      break;
    }
  }

  switch (i) {
  case 0:
    std::cout << "[ " + levels[0] + " ]" << std::endl;
    this->debug();
  case 1:
    std::cout << "[ " + levels[1] + " ]" << std::endl;
    this->info();
  case 2:
    std::cout << "[ " + levels[2] + " ]" << std::endl;
    this->warning();
  case 3:
    std::cout << "[ " + levels[3] + " ]" << std::endl;
    this->error();
    return;
  default:
    std::cout << "[ Level " + level + " not found ]" << std::endl;
    return;
  }
}

void Harl::debug() {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month"
      << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}
