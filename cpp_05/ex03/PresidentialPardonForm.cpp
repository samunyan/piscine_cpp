/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:47:22 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 19:48:17 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::formAction() const {
  std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs) {
  o << rhs.getName() << ", PresidentialPardonForm signed " << std::boolalpha
    << rhs.getIsSigned() << std::noboolalpha << ", signature grade "
    << rhs.getSignGrade() << ", execution grade " << rhs.getExecuteGrade()
    << ".";
  return o;
}