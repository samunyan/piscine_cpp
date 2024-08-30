/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:44 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:45 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "colors.hpp"
#include "input.hpp"
#include <iostream>
#include <string>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  bool addContact();
  bool showContact() const;

private:
  Contact _contacts[8];
  int _indexNextContact;
};

#endif
