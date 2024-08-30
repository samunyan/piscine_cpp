/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:19:53 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 19:21:39 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robot", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::formAction() const {
  std::cout << "<DRILLING NOISES>" << std::endl;
  std::srand(static_cast<unsigned>(std::time(NULL)));
  int n = std::rand() % 2;
  if (n)
    std::cout << this->_target + " has been robotomized." << std::endl;
  else
    std::cout << "The robotomy of " + this->_target + " failed." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs) {
  o << rhs.getName() << ", RobotomyRequestForm signed " << std::boolalpha
    << rhs.getIsSigned() << std::noboolalpha << ", signature grade "
    << rhs.getSignGrade() << ", execution grade " << rhs.getExecuteGrade()
    << ".";
  return o;
}
