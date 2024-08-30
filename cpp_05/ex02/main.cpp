/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:15:55 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/05 16:18:30 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <iomanip>

void testShrub(const std::string &title, const std::string &nameBcrat,
               int grade, const std::string &target) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << title << RESET_ALL << std::endl;
  try {
    Bureaucrat bcrat(nameBcrat, grade);
    std::cout << bcrat << std::endl;
    ShrubberyCreationForm form(target);
    std::cout << form << std::endl;
    bcrat.signForm(form);
    std::cout << form << std::endl;
    bcrat.executeForm(form);
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

void testRobot(const std::string &title, const std::string &nameBcrat,
               int grade, const std::string &target) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << title << RESET_ALL << std::endl;
  try {
    Bureaucrat bcrat(nameBcrat, grade);
    std::cout << bcrat << std::endl;
    RobotomyRequestForm form(target);
    std::cout << form << std::endl;
    bcrat.signForm(form);
    std::cout << form << std::endl;
    bcrat.executeForm(form);
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

void testPardon(const std::string &title, const std::string &nameBcrat,
                int grade, const std::string &target) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << title << RESET_ALL << std::endl;
  try {
    Bureaucrat bcrat(nameBcrat, grade);
    std::cout << bcrat << std::endl;
    PresidentialPardonForm form(target);
    std::cout << form << std::endl;
    bcrat.signForm(form);
    std::cout << form << std::endl;
    bcrat.executeForm(form);
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

int main() {
  std::cout << BG_YELLOW "***** SHRUB *****" RESET_ALL << std::endl;
  testShrub("The bureaucrat can sign and execute", "Fred", 1, "home1");
  testShrub("The bureaucrat can sign and execute", "Fred", 10, "home2");
  testShrub("The bureaucrat can sign but not execute", "Fred", 145, "home3");
  testShrub("The bureaucrat can neither sign nor execute", "Fred", 146,
            "home4");
  std::cout << BG_YELLOW "***** ROBOT *****" RESET_ALL << std::endl;
  testRobot("The bureaucrat can sign and execute", "Fred", 1, "robot1");
  testRobot("The bureaucrat can sign and execute", "Fred", 10, "robot2");
  testRobot("The bureaucrat can sign but not execute", "Fred", 72, "robot3");
  testRobot("The bureaucrat can neither sign nor execute", "Fred", 146,
            "robot4");
  std::cout << BG_YELLOW "***** PARDON *****" RESET_ALL << std::endl;
  testPardon("The bureaucrat can sign and execute", "Fred", 1, "barney1");
  testPardon("The bureaucrat can sign but not execute", "Fred", 25, "barney2");
  testPardon("The bureaucrat can neither sign nor execute", "barney3", 26,
             "barney4");
  return 0;
}
