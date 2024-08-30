/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:24:18 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/04 21:40:21 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <utility>

class BitcoinExchange {
public:
  explicit BitcoinExchange(const std::string &inputFile);
  virtual ~BitcoinExchange();
  void setRates();
  const std::map<std::string, double> &getRates() const;
  const std::string &getInputFile() const;
  void processStats() const;

private:
  std::map<std::string, double> _rates;
  const std::string _inputFile;
  BitcoinExchange(const BitcoinExchange &src);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
};

bool fileIsValid(const std::string &pathname);
bool rateFormatIsValid(const std::string &line);
bool statFormatIsValid(const std::string &line);
bool dateIsValid(const std::string &date);
bool valueIsValid(const std::string &val, double min, double max);

std::string getDate(const std::string &line, const std::string &delim);
double getVal(const std::string &line, const std::string &delim);
bool getYear(const std::string &line, int &res);
bool getMonth(const std::string &line, int &res);
bool getDay(const std::string &line, int &res, int year, int month);

#endif
