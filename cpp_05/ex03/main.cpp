/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:15:55 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/11 22:29:31 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "colors.hpp"
#include <iomanip>

void test(const std::string &title, const std::string &formName,
          const std::string &target) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << title << RESET_ALL << std::endl;
  Intern intern;
  AForm *form = nullptr;
  try {
    Bureaucrat bcrat("Fred", 1);
    std::cout << bcrat << std::endl;
    form = intern.makeForm(formName, target);
    bcrat.signForm(*form);
    std::cout << *form << std::endl;
    bcrat.executeForm(*form);
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
  delete form;
}

int main() {
  test("a valid Shrubbery form", "shrubbery", "home_1");
  test("a valid Robotomy form", "robotomy", "home_2");
  test("a valid Pardon form", "pardon", "home_3");
  test("an invalid form", "blabla", "home_4");

  return 0;
}
