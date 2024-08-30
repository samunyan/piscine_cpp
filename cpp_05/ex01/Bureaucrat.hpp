/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:09:26 by samunyan          #+#    #+#             */
/*   Updated: 2023/09/14 15:09:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat {
public:
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat(const std::string &name, int grade);
  virtual ~Bureaucrat();
  const std::string &getName() const;
  const int &getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(Form &f) const;
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
  int _grade;
  Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
