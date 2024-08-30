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
#include "Form.hpp"
#include "colors.hpp"
#include <iomanip>

void test(const std::string &title, const std::string &nameBcrat, int grade,
          const std::string &nameForm, int signGrade, int executeGrade) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << title << RESET_ALL << std::endl;
  try {
    Bureaucrat bcrat(nameBcrat, grade);
    std::cout << bcrat << std::endl;
    Form form(nameForm, signGrade, executeGrade);
    std::cout << form << std::endl;
    bcrat.signForm(form);
    std::cout << form << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

int main() {

  test("The bureaucrat can sign the form", "Fred", 1, "Form", 10, 11);
  test("The bureaucrat's grade is too low to sign the form", "Fred", 20, "Form",
       10, 11);
  test("The form's grade is too high", "Fred", 20, "Form", 0, 11);
  test("The form's grade is too low", "Fred", 20, "Form", 10, 200);
  return 0;
}
