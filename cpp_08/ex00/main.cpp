/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:54:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/25 02:03:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "easyfind.hpp"
#include <deque>
#include <iomanip>
#include <list>
#include <vector>

template <typename T> static void test(const std::string &testName, T &ct);
static void printTestName(const std::string &type);
static void printSubTestName(int val);
template <typename T> void printContainer(T &ct);

int main() {
  std::vector<int> vec;
  test("vector", vec);
  std::deque<int> dq;
  test("deque", dq);
  std::list<int> lst;
  test("list", lst);
  return 0;
}

template <typename T> static void test(const std::string &testName, T &ct) {
  try {
    printTestName(testName);
    for (int i(0); i < 10; ++i) {
      ct.push_back(i);
    }
    printContainer(ct);
    int val = 5;
    printSubTestName(val);
    easyfind(ct, val);
    std::cout << FG_GREEN << "found" << RESET_ALL << std::endl;
    val = 10;
    printSubTestName(val);
    easyfind(ct, val);
    std::cout << FG_GREEN << "found" << RESET_ALL << std::endl;

  } catch (std::exception &e) {
    std::cerr << FG_RED << e.what() << RESET_ALL << std::endl;
  }
}

static void printTestName(const std::string &type) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << type + " container" << RESET_ALL << std::endl;
}

static void printSubTestName(int val) {
  std::cout << BG_LGRAY << FG_BLACK << "find " << val << RESET_ALL << std::endl;
}

template <typename T> void printContainer(T &ct) {
  typename T::iterator it;
  for (it = ct.begin(); it != ct.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
}
