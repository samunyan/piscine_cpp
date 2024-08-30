#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm(const AForm &src);
  AForm(const std::string &name, int signGrade, int executeGrade);
  virtual ~AForm();
  const std::string &getName() const;
  bool getIsSigned() const;
  const int &getSignGrade() const;
  const int &getExecuteGrade() const;
  void beSigned(const Bureaucrat &bcrat);
  void execute(const Bureaucrat &executor) const;
  virtual void formAction() const = 0;
  class GradeTooHighException : public std::runtime_error {
  public:
    GradeTooHighException();
  };
  class GradeTooLowException : public std::runtime_error {
  public:
    GradeTooLowException();
  };
  class FormNotSignedException : public std::runtime_error {
  public:
    FormNotSignedException();
  };
  class BcratSignTooLowException : public std::runtime_error {
  public:
    BcratSignTooLowException();
  };
  class BcratExecTooLowException : public std::runtime_error {
  public:
    BcratExecTooLowException();
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _executeGrade;
  AForm();
  AForm &operator=(const AForm &rhs);
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif
