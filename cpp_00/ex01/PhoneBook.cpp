/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:41 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:42 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _indexNextContact(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact() {
  this->_indexNextContact %= 8;
  if (!this->_contacts[this->_indexNextContact].add())
    return (false);
  this->_indexNextContact++;
  return (true);
}

bool PhoneBook::showContact() const {
  bool flag = false;
  for (int i = 0; i < 8; i++)
    if (this->_contacts[i].show())
      flag = true;

  if (!flag) {
    std::cout << GREEN << "No contacts to show." << RESET << std::endl;
    return (true);
  }

  std::string input;
  if (!getInput("Enter index", numeric, input))
    return (false);
  if (input.length() != 1 ||
      input.find_first_not_of("01234567") != std::string::npos) {
    std::cout << RED << "Index out of range." << RESET << std::endl;
    return (true);
  }

  flag = false;
  for (int i = 0; i < 8; i++)
    if (this->_contacts[i].show(input.at(0) - '0'))
      flag = true;
  if (!flag)
    std::cout << RED << "Index out of range." << RESET << std::endl;

  return (true);
}
