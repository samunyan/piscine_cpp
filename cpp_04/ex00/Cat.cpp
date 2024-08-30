/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:18:58 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:18:59 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat") { std::cout << "Default constructor for Cat\n"; }

Cat::Cat(const Cat &src) : Animal(src) {
  std::cout << "Copy constructor for Cat\n";
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Assignment operator for Cat\n";
  if (this == &rhs)
    return *this;
  Animal::operator=(rhs);
  return *this;
}

Cat::~Cat() { std::cout << "Default destructor for Cat\n"; }

void Cat::makeSound() const { std::cout << "Meow\n"; }
