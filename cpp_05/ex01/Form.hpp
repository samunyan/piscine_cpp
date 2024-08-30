/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:23:50 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 16:15:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
public:
  Form(const Form &src);
  Form(const std::string &name, int signGrade, int executeGrade);
  virtual ~Form();
  const std::string &getName() const;
  bool getIsSigned() const;
  const int &getSignGrade() const;
  const int &getExecuteGrade() const;
  void beSigned(const Bureaucrat &bcrat);
  class GradeTooHighException : public std::runtime_error {
  public:
    GradeTooHighException();
  };
  class GradeTooLowException : public std::runtime_error {
  public:
    GradeTooLowException();
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _executeGrade;
  Form();
  Form &operator=(const Form &rhs);
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
