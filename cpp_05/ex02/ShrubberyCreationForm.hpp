/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:48:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 17:45:10 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm();
  virtual void formAction() const;

private:
  std::string _target;
  ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs);

#endif
