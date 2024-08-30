/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:10:12 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 20:22:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Intern {
public:
  Intern();
  virtual ~Intern();
  AForm *makeForm(const std::string &formName,
                         const std::string &target) ;
  class InvalidFormException : public std::runtime_error {
  public:
    InvalidFormException();
  };

private:
  AForm *_makeShrub(const std::string &target);
  AForm *_makeRobot(const std::string &target);
  AForm *_makePardon(const std::string &target);
  typedef struct s_forms {
    std::string _name;
    AForm *(Intern::*_func)(const std::string &target);
  } t_forms;
  Intern(const Intern &src);
  Intern &operator=(const Intern &rhs);
};

#endif
