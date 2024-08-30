/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:46:51 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 16:15:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade),
      _executeGrade(src._executeGrade) {}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade),
      _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1)
    throw Form::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150)
    throw Form::GradeTooLowException();
}

Form::~Form() {}

const std::string &Form::getName() const { return this->_name; }

bool Form::getIsSigned() const { return this->_isSigned; }

const int &Form::getSignGrade() const { return this->_signGrade; }

const int &Form::getExecuteGrade() const { return this->_executeGrade; }

void Form::beSigned(const Bureaucrat &bcrat) {
  if (bcrat.getGrade() > this->_signGrade)
    throw Form::GradeTooLowException();
  this->_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade too high") {}

Form::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade too low") {}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
  o << rhs.getName() << ", form signed " << std::boolalpha << rhs.getIsSigned()
    << std::noboolalpha << ", signature grade " << rhs.getSignGrade()
    << ", execution grade " << rhs.getExecuteGrade() << ".";
  return o;
}
