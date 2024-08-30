/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:34 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:35 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void showMenu() {
  const std::string &info("Enter ADD to add a new contact, "
                          "SEARCH to search a contact\n"
                          "or EXIT to exit the phonebook: ");

  std::cout << BOLDMAGENTA << info << RESET;
}

bool executeCommand(const std::string &command, PhoneBook &phonebook) {
  if (command == "ADD")
    return (phonebook.addContact());
  if (command == "SEARCH")
    return (phonebook.showContact());
  return (command != "EXIT");
}

int main() {
  PhoneBook phonebook;
  std::string input;

  showMenu();
  while (std::getline(std::cin, input)) {
    if (std::cin.eof() || !executeCommand(input, phonebook))
      break;
    showMenu();
  }
  return 0;
}
