/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:48:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 19:20:34 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrub", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::formAction() const {
  std::string tree("              ,@@@@@@@,				\n"
                   "      ,,,.   ,@@@@@@/@@,  .oo8888o.		\n"
                   "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o		\n"
                   "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		\n"
                   "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		\n"
                   "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'		\n"
                   "  `&%\\ ` /%&'    |.|        \\ '|8'		\n"
                   "      |o|        | |         | |			\n"
                   "      |.|        | |         | |			\n"
                   "   \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_	\n");
  std::string fileName(this->_target + "_shrubbery");
  std::ofstream out(fileName.c_str(), std::ofstream::out | std::ofstream::app);
  if (out.is_open()) {
    out << tree;
    out.close();
  } else
    throw std::runtime_error(
        (fileName + ": Failed to open file in formAction().").c_str());
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs) {
  o << rhs.getName() << ", ShrubberyCreationForm signed " << std::boolalpha
    << rhs.getIsSigned() << std::noboolalpha << ", signature grade "
    << rhs.getSignGrade() << ", execution grade " << rhs.getExecuteGrade()
    << ".";
  return o;
}
