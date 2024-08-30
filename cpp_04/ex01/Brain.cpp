/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:19:26 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/13 00:19:27 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

static std::string int_to_string(int n) {
  std::stringstream ss;
  ss << n;
  std::string str(ss.str());
  return str;
}

Brain::Brain() {
  std::cout << "Default constructor for Brain\n";
  this->_ideas = new std::string[100];
  int n = 0;
  for (int i(0); i < 100; ++i) {
    this->_ideas[i] = int_to_string(n++);
  }
}

Brain::Brain(const Brain &src) {
  std::cout << "Copy constructor for Brain\n";
  this->_ideas = new std::string[100];
  for (int i(0); i < 100; ++i) {
    this->_ideas[i] = src.getIdeas()[i] + "_cc";
  }
}

Brain &Brain::operator=(const Brain &rhs) {
  std::cout << "Assignment operator for Brain\n";
  if (this == &rhs)
    return *this;
  for (int i(0); i < 100; ++i) {
    this->_ideas[i] = rhs.getIdeas()[i] + "_ca";
  }
  return *this;
}

Brain::~Brain() {
  std::cout << "Default destructor for Brain\n";
  delete[] this->_ideas;
}

const std::string *Brain::getIdeas() const { return this->_ideas; }

std::ostream &operator<<(std::ostream &o, const Brain &rhs) {
  o << "Brain's ideas:\n";
  for (int i(0); i < 100; ++i) {
    o << rhs.getIdeas()[i] + " ";
  }
  o << std::endl;
  return o;
}
