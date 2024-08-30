/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:10:12 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 20:24:52 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::InvalidFormException::InvalidFormException()
    : std::runtime_error("form name not valid") {}

AForm *Intern::_makeShrub(const std::string &target) {
  return (new ShrubberyCreationForm(target));
}
AForm *Intern::_makeRobot(const std::string &target) {
  return (new RobotomyRequestForm(target));
}
AForm *Intern::_makePardon(const std::string &target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  static t_forms forms[3] = {{"shrubbery", &Intern::_makeShrub},
                             {"robotomy", &Intern::_makeRobot},
                             {"pardon", &Intern::_makePardon}};
  for (int i(0); i < 3; ++i) {
    if (formName == forms[i]._name) {
      AForm *form = (this->*(forms[i]._func))(target);
      std::cout << "Intern creates " << *form << std::endl;
      return (form);
    }
  }
  throw InvalidFormException();
}
