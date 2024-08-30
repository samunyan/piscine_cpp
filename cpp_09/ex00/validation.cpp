/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:24:14 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/05 14:24:14 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool fileIsValid(const std::string &pathname) {
  struct stat buf;
  if (stat(pathname.c_str(), &buf) == -1)
    throw(std::runtime_error(pathname + " is an invalid file path"));
  if (buf.st_mode & S_IFDIR)
    throw(std::runtime_error(pathname + " is a directory"));
  if (buf.st_mode & S_IXUSR)
    throw(std::runtime_error(pathname + " is an executable"));
  return (buf.st_mode & S_IFREG);
}

bool rateFormatIsValid(const std::string &line) {
  for (std::string::const_iterator it = line.begin(); it != line.end(); ++it) {
    if (isspace(*it))
      return false;
  }
  size_t c = line.find_first_of(',');
  if (c == std::string::npos || c != line.find_last_of(','))
    return false;
  std::string date(line.substr(0, c));
  std::string val(line.substr(c + 1));
  if (!dateIsValid(date) ||
      !valueIsValid(val, 0, std::numeric_limits<double>::max()))
    return false;
  return true;
}

bool statFormatIsValid(const std::string &line) {
  size_t c = line.find_first_of('|');
  if (c == std::string::npos || c != line.find_last_of('|'))
    return false;
  std::string date(line.substr(0, c));
  if (date.empty() || line.at(date.length() - 1) != ' ')
    return false;
  for (std::string::const_iterator it = date.begin(); it != --date.end();
       ++it) {
    if (isspace(*it))
      return false;
  }
  date.erase(date.find(' '), 1);
  std::string val(line.substr(c + 1));
  if (val.empty() || val.at(0) != ' ')
    return false;
  for (std::string::const_iterator it = ++val.begin(); it != val.end(); ++it) {
    if (isspace(*it))
      return false;
  }
  val.erase(val.find(' '), 1);
  if (!dateIsValid(date) || !valueIsValid(val, 0, 1000))
    return false;
  return true;
}

bool dateIsValid(const std::string &date) {
  if (date.empty())
    return false;
  std::istringstream is(date);
  std::string line;
  int year, month, day;
  std::getline(is, line, '-');
  if (!getYear(line, year))
    return false;
  std::getline(is, line, '-');
  if (!getMonth(line, month))
    return false;
  std::getline(is, line);
  if (!getDay(line, day, year, month))
    return false;
  return true;
}

bool valueIsValid(const std::string &val, double min, double max) {
  if (val.empty())
    return false;
  size_t c = val.find_first_of('.');
  if (c != std::string::npos && c != val.find_last_of('.'))
    return false;
  if (val.find_first_not_of("0123456789.") != std::string::npos)
    return false;
  std::istringstream is(val);
  double d;
  is >> d;
  return (d >= min && d <= max);
}