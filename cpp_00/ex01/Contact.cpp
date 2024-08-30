/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:16 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:17 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int Contact::_nbContacts = 0;

Contact::Contact() : _index(Contact::_nbContacts) { Contact::_nbContacts++; }

Contact::~Contact() { Contact::_nbContacts--; }

bool Contact::add() {
  std::string input;

  if (!getInput("First name", alpha, input))
    return (false);
  setFirstName(input);
  if (!getInput("Last name", alpha, input))
    return (false);
  setLastName(input);
  if (!getInput("Nickname", alpha, input))
    return (false);
  setNickname(input);
  if (!getInput("Phone Number", numeric, input))
    return (false);
  setPhoneNum(input);
  if (!getInput("Secret", alpha, input))
    return (false);
  setSecret(input);

  return (true);
}

static std::string truncateIfBigger(const std::string &field, size_t width) {
  std::string str(field);
  if (str.length() > width) {
    str.resize(width - 1);
    str += ".";
  }
  return (str);
}

bool Contact::show() const {
  if (this->_firstName.empty())
    return (false);

  std::cout << std::setw(10) << this->_index << "|" << std::setw(10)
            << truncateIfBigger(this->_firstName, 10) << "|" << std::setw(10)
            << truncateIfBigger(this->_lastName, 10) << "|" << std::setw(10)
            << truncateIfBigger(this->_nickname, 10) << std::endl;
  return (true);
}

bool Contact::show(int index) const {
  if (this->_index != index)
    return (false);
  if (this->_firstName.empty())
    return (false);

  std::cout << GREEN << this->_index << std::endl
            << this->_firstName << std::endl
            << this->_lastName << std::endl
            << this->_phoneNumber << std::endl
            << this->_secret << std::endl
            << RESET;

  return (true);
}

void Contact::setFirstName(const std::string &str) { this->_firstName = str; }

void Contact::setLastName(const std::string &str) { this->_lastName = str; }

void Contact::setNickname(const std::string &str) { this->_nickname = str; }

void Contact::setPhoneNum(const std::string &str) { this->_phoneNumber = str; }

void Contact::setSecret(const std::string &str) { this->_secret = str; }
