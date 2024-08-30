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
#include "colors.hpp"
#include <iomanip>

void test(const std::string &test, const std::string &name, int grade) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << test << RESET_ALL << std::endl;
  try {
    Bureaucrat b(name, grade);
    std::cout << b << std::endl;
    std::cout << "-: ";
    b.decrementGrade();
    std::cout << b << std::endl;
    std::cout << "+: ";
    b.incrementGrade();
    std::cout << b << std::endl;
    std::cout << "+: ";
    b.incrementGrade();
    std::cout << b << std::endl;
  } catch (const std::exception &e) {
    std::cerr << FG_RED "Error: " << e.what() << RESET_ALL << std::endl;
  }
}

int main() {
  test("an average bureaucrat", "Fred", 75);
  test("a bureaucrat on the edge", "Wilma", 149);
  test("a bureaucrat trying too hard", "Pebbles", 1);
  test("a bureaucrat tipping over", "Barney", 150);
  test("a grade too low to start with", "Betty", 151);
  test("a grade too high to start with", "Bamm-Bamm", 0);
  return 0;
}
