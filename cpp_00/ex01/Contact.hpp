/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:21 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:22 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "colors.hpp"
#include "input.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
public:
  Contact();
  ~Contact();
  bool add();
  bool show() const;
  bool show(int index) const;
  void setFirstName(const std::string &str);
  void setLastName(const std::string &str);
  void setNickname(const std::string &str);
  void setPhoneNum(const std::string &str);
  void setSecret(const std::string &str);

private:
  int _index;
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _secret;
  static int _nbContacts;
};

#endif
