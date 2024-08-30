/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:19:53 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 19:21:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm();
  virtual void formAction() const;

private:
  std::string _target;
  RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &rhs);

#endif
