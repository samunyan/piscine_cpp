/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:15:41 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 16:15:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade),
      _executeGrade(src._executeGrade) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade),
      _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1)
    throw AForm::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150)
    throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return this->_name; }

bool AForm::getIsSigned() const { return this->_isSigned; }

const int &AForm::getSignGrade() const { return this->_signGrade; }

const int &AForm::getExecuteGrade() const { return this->_executeGrade; }

void AForm::beSigned(const Bureaucrat &bcrat) {
  if (bcrat.getGrade() > this->_signGrade)
    throw AForm::GradeTooLowException();
  this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!this->_isSigned)
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > this->_executeGrade)
    throw AForm::BcratExecTooLowException();
  this->formAction();
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("grade too high") {}

AForm::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("grade too low") {}

AForm::FormNotSignedException::FormNotSignedException()
    : std::runtime_error("form not signed") {}

AForm::BcratSignTooLowException::BcratSignTooLowException()
    : std::runtime_error("sign grade too low") {}

AForm::BcratExecTooLowException::BcratExecTooLowException()
    : std::runtime_error("execute grade too low") {}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
  o << rhs.getName() << ", AForm signed " << std::boolalpha << rhs.getIsSigned()
    << std::noboolalpha << ", signature grade " << rhs.getSignGrade()
    << ", execution grade " << rhs.getExecuteGrade() << ".";
  return o;
}
