/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:17:40 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/15 14:17:43 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool signCheck(const std::string &s) {
  if (s.at(0) == '-' && s.find_first_of("-+") != s.find_last_of("-+"))
    return (false);
  if (s.at(0) == '+' && s.find_first_of("-+") != s.find_last_of("-+"))
    return (false);
  return (true);
}

static bool isChar(const std::string &s) {
  return (s.length() == 1 &&
          s.find_first_of("0123456789") == std::string::npos);
}

static bool isInt(const std::string &s) {
  return (signCheck(s) &&
          s.find_first_not_of("+-0123456789") == std::string::npos);
}

static bool isFloat(const std::string &s) {
  if (!signCheck(s))
    return (false);
  if (s == "inff" || s == "-inff" || s == "nanf")
    return (true);
  return (s.find_first_not_of("+-0123456789.f") == std::string::npos &&
          s.find_first_of('.') != std::string::npos &&
          s.find_first_of('.') == s.find_last_of('.') &&
          s.length() - 1 == s.find_first_of('f'));
}

static bool isDouble(const std::string &s) {

  if (!signCheck(s))
    return (false);
  if (s == "inf" || s == "-inf" || s == "nan")
    return (true);
  return (s.find_first_not_of("+-0123456789.") == std::string::npos &&
          s.find_first_of('.') != std::string::npos &&
          s.find_first_of('.') == s.find_last_of('.') &&
          s.find_first_of('f') == std::string::npos);
}

static void print(double d) {
  std::stringstream check;
  std::cout << "Double: " << d;
  check << d;
  if (check.str().find("inf") == std::string::npos &&
      check.str().find("nan") == std::string::npos &&
      check.str().find_first_of('.') == std::string::npos)
    std::cout << ".0";
  std::cout << std::endl;
}

static void print(float f) {
  std::stringstream check;
  std::cout << "Float: " << f;
  check << f;
  if (check.str().find("inf") == std::string::npos &&
      check.str().find("nan") == std::string::npos &&
      check.str().find_first_of('.') == std::string::npos)
    std::cout << ".0";
  std::cout << "f" << std::endl;
}

static void print(int i, double check) {
  std::cout << "Int: ";
  if (check < std::numeric_limits<int>::min() ||
      check > std::numeric_limits<int>::max() || check != check)
    std::cout << "impossible" << std::endl;
  else
    std::cout << i << std::endl;
}

static void print(char c, double check) {
  std::cout << "Char: ";
  if (check < std::numeric_limits<char>::min() ||
      check > std::numeric_limits<char>::max() || check != check)
    std::cout << "impossible" << std::endl;
  else if (!std::isprint(c))
    std::cout << "non displayable" << std::endl;
  else
    std::cout << c << std::endl;
}

static ScalarConverter::t_type getType(const std::string &s) {
  if (isChar(s))
    return (ScalarConverter::CHAR);
  else if (isInt(s))
    return (ScalarConverter::INT);
  else if (isFloat(s))
    return (ScalarConverter::FLOAT);
  else if (isDouble(s))
    return (ScalarConverter::DOUBLE);
  else
    throw std::runtime_error("not a valid scalar type");
}

static void convertToDouble(const std::string &s) {
  double d;
  if (s == "nan")
    d = std::numeric_limits<double>::quiet_NaN();
  else if (s == "inf")
    d = std::numeric_limits<double>::infinity();
  else if (s == "-inf")
    d = -std::numeric_limits<double>::infinity();
  else {
    std::stringstream ss(s);
    ss >> d;
  }
  print(static_cast<char>(d), d);
  print(static_cast<int>(d), d);
  print(static_cast<float>(d));
  print(d);
}

static void convertToFloat(const std::string &s) {
  float f;
  if (s == "nanf")
    f = std::numeric_limits<float>::quiet_NaN();
  else if (s == "inff")
    f = std::numeric_limits<float>::infinity();
  else if (s == "-inff")
    f = -std::numeric_limits<float>::infinity();
  else {
    std::stringstream ss(s);
    ss >> f;
  }
  print(static_cast<char>(f), f);
  print(static_cast<int>(f), f);
  print(f);
  print(static_cast<double>(f));
}

static void convertToInt(const std::string &s) {
  std::stringstream ss(s);
  double check;
  ss >> check;
  ss.clear();
  ss.str(std::string());
  ss << s;
  int i;
  ss >> i;
  print(static_cast<char>(i), check);
  print(i, check);
  print(static_cast<float>(i));
  print(static_cast<double>(i));
}

static void convertToChar(const std::string &s) {
  std::stringstream ss(s);
  double check;
  ss >> check;
  ss.clear();
  ss.str(std::string());
  ss << s;
  char c;
  ss >> c;
  print(c, check);
  print(static_cast<int>(c), check);
  print(static_cast<float>(c));
  print(static_cast<double>(c));
}

void ScalarConverter::convert(const std::string &s) {
  switch (getType(s)) {
  case DOUBLE:
    convertToDouble(s);
    break;
  case FLOAT:
    convertToFloat(s);
    break;
  case INT:
    convertToInt(s);
    break;
  case CHAR:
    convertToChar(s);
    break;
  }
}
