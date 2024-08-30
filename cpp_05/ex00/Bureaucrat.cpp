/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:09:26 by samunyan          #+#    #+#             */
/*   Updated: 2023/09/14 15:09:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (this->_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (this->_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return this->_name; }

const int &Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade too low") {}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
  o << rhs.getName() + ", bureaucrat grade " << rhs.getGrade() << ".";
  return o;
}