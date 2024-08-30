/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:51:15 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/04 21:52:31 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &expr) : _expr(expr) {}

RPN::~RPN() {}

static bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '/' || c == '*');
}

static bool isOperand(char c) { return ('0' <= c && c <= '9'); }

static double doOp(double a, double b, char c) {
  static std::string operators("+-/*");
  int op = static_cast<int>(operators.find(c));
  switch (op) {
  case 0:
    return b + a;
  case 1:
    return b - a;
  case 2:
    if (a == 0)
      throw std::overflow_error("divide by zero exception");
    return static_cast<double>(b) / a;
  default:
    return b * a;
  }
}

double RPN::getResult() const {
  std::stack<double> stack;
  double a, b, res;
  std::string s(this->_expr);
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  std::string::const_iterator it = s.begin();
  std::string::const_iterator ite = s.end();
  for (; it != ite; ++it) {
    if (isOperand(*it)) {
      stack.push(*it - '0');
    } else if (isOperator(*it) && stack.size() >= 2) {
      a = stack.top();
      stack.pop();
      b = stack.top();
      stack.pop();
      stack.push(doOp(a, b, *it));
    } else {
      throw std::runtime_error("invalid expression");
    }
  }
  res = stack.top();
  stack.pop();
  if (!stack.empty())
    throw std::runtime_error("invalid expression");
  return res;
}