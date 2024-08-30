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

#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>
#include <iomanip>
#include <list>

static void testMutantStack();
static void testList();
template <typename T> void printContainer(T &c);
template <> void printContainer(std::stack<int> &c);
static void printTestName(const std::string &type);
static void printSubTestName(const std::string &str);

int main() {
  testMutantStack();
  testList();
  return 0;
}

static void testMutantStack() {
  printTestName("MutantStack");
  MutantStack<int> mstack;

  printSubTestName("Push 5, 17");
  mstack.push(5);
  mstack.push(17);
  printContainer(mstack);

  printSubTestName("Pop");
  mstack.pop();
  printContainer(mstack);

  printSubTestName("Push 3, 5, 737, 0");
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  printContainer(mstack);

  printSubTestName("Stack's copy constructor with previous MutanStack as arg");
  std::stack<int> s(mstack);
  printContainer(s);
}

static void testList() {
  printTestName("List");
  std::list<int> lst;

  printSubTestName("Push 5, 17");
  lst.push_back(5);
  lst.push_back(17);
  printContainer(lst);

  printSubTestName("Pop");
  lst.pop_back();
  printContainer(lst);

  printSubTestName("Push 3, 5, 737, 0");
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);
  printContainer(lst);

  printSubTestName("List's copy constructor with previous List as arg");
  std::list<int> s(lst);
  printContainer(s);
}


template <typename T> void printContainer(T &c) {
  typename T::reverse_iterator it = c.rbegin();
  typename T::reverse_iterator ite = c.rend();
  for (; it != ite; ++it)
    std::cout << FG_BLUE << *it << ' ';
  std::cout << RESET_ALL << std::endl;
}

template <> void printContainer(std::stack<int> &c) {
  std::stack<int> s(c);
  while (s.size()) {
    std::cout << FG_BLUE << s.top() << ' ';
    s.pop();
  }
  std::cout << RESET_ALL << std::endl;
}



static void printTestName(const std::string &type) {
  static int n;
  std::cout << BG_BLUE "test " << ++n << ": " << std::setw(35) << std::left
            << type + " container" << RESET_ALL << std::endl;
}

static void printSubTestName(const std::string &str) {
  std::cout << BG_LGRAY << FG_BLACK << str << RESET_ALL << std::endl;
}



