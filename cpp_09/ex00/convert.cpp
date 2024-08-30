/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:26:44 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/05 14:26:44 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string getDate(const std::string &line, const std::string &delim) {
  std::string date;
  size_t pos = line.find(delim);
  std::istringstream iss(line.substr(0, pos));
  iss >> date;
  return date;
}

double getVal(const std::string &line, const std::string &delim) {
  double val;
  size_t pos = line.find(delim);
  std::istringstream iss(line.substr(pos + 1));
  iss >> val;
  return val;
}

bool getYear(const std::string &line, int &res) {
  std::stringstream conv;
  if (line.size() != 4 ||
      line.find_first_not_of("0123456789") != std::string::npos)
    return false;
  conv.str(line);
  conv >> res;
  return true;
}

bool getMonth(const std::string &line, int &res) {
  std::stringstream conv;
  if (line.size() != 2 ||
      line.find_first_not_of("0123456789") != std::string::npos)
    return false;
  conv.str(line);
  conv >> res;
  return (1 <= res && res <= 12);
}

bool getDay(const std::string &line, int &res, int year, int month) {
  std::stringstream conv;
  if (line.size() != 2 ||
      line.find_first_not_of("0123456789") != std::string::npos)
    return false;
  conv.str(line);
  conv >> res;
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      return (res >= 1 && res <= 29);
    else
      return (res >= 1 && res <= 28);
  } else if (month == 4 || month == 6 || month == 9 || month == 11)
    return (res >= 1 && res <= 30);
  else
    return (res >= 1 && res <= 31);
}
