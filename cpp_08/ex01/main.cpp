/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:13:09 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/26 23:13:09 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"
#include <iomanip>
#include <iostream>

static void test(const std::string &testName, unsigned int maxLen,
                 unsigned int count);

int main() {
  std::srand(std::time(nullptr));
  std::cout << std::setw(60) << std::left
            << BG_LGRAY FG_BLACK "ADD SOME NUMBERS ONE BY ONE" << RESET_ALL
            << std::endl;
  test("Normal case", 6, 5);
  test("Normal case", 50000, 20000);
  test("Container is too small", 10, 30);
  test("Container is empty", 0, 0);
  test("Container has only 1 element", 3, 1);

  std::cout << std::setw(60) << std::left << std::endl
            << BG_LGRAY FG_BLACK "ADD MANY NUMBERS IN ONE CALL" << RESET_ALL
            << std::endl;
  test("Normal case", 60000, 50000);
  test("Normal case", 50000, 30000);
  test("Container is too small", 10, 30000);
  return 0;
}

static int getRandomNumber() { return (std::rand() % 10000); }

static void test(const std::string &testName, unsigned int maxLen,
                 unsigned int count) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << testName << RESET_ALL << std::endl;
  std::cout << UNDERLINED "Max length is " << maxLen << ", add " << count
            << " number(s)" RESET_ALL << std::endl;
  try {
    Span sp(maxLen);
    if (count <= 20000) {
      for (unsigned int i(0); i < count; ++i) {
        sp.addNumber(getRandomNumber());
        if (count <= 10)
          std::cout << FG_LYELLOW << sp << RESET_ALL << std::endl;
      }
    } else
      sp.addRange(count);
    if (count <= 30)
      std::cout << FG_GREEN << sp << RESET_ALL << std::endl;
    else
      std::cout << FG_GREEN << "[big span]" << RESET_ALL << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (Span::SpanIsFullException &e) {
    std::cout << FG_RED << "Error: " << e.what() << RESET_ALL << std::endl;
  } catch (Span::NoSpanException &e) {
    std::cout << FG_RED << "Error: " << e.what() << RESET_ALL << std::endl;
  } catch (std::exception &e) {
    std::cout << FG_RED << "Error: " << e.what() << RESET_ALL << std::endl;
  } catch (...) {
    std::cout << FG_RED << "Unkown error" << RESET_ALL << std::endl;
  }
}