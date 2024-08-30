/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:47:23 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 19:48:17 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm(const std::string &target);
  virtual ~PresidentialPardonForm();
  virtual void formAction() const;

private:
  std::string _target;
  PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs);

#endif
