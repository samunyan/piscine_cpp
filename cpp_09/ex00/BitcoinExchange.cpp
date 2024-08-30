/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:24:18 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/05 14:37:47 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &inputFile)
    : _inputFile(inputFile) {}

BitcoinExchange::~BitcoinExchange() {}

const std::map<std::string, double> &BitcoinExchange::getRates() const {
  return this->_rates;
}
const std::string &BitcoinExchange::getInputFile() const {
  return this->_inputFile;
}

void BitcoinExchange::setRates() {
  if (!fileIsValid("data.csv"))
    throw;
  std::ifstream input("data.csv");
  if (!input)
    throw std::runtime_error("could not open data file");
  std::string line;
  std::getline(input, line);
  if (line != "date,exchange_rate") {
    input.close();
    throw std::runtime_error("wrong header in data file => \"" + line + "\"");
  }
  while (std::getline(input, line)) {
    if (line.empty())
      continue;
    if (!rateFormatIsValid(line)) {
      input.close();
      throw std::runtime_error("bad format in data file => \"" + line + "\"");
    }
    std::pair<std::string, double> pair =
        std::make_pair(getDate(line, ","), getVal(line, ","));
    std::pair<std::map<std::string, double>::const_iterator, bool> it =
        this->_rates.insert(pair);
    if (!it.second) {
      input.close();
      throw std::runtime_error("duplicate in data.csv => \"" + line + "\"");
    }
  }
  input.close();
}

static void processOneStat(const std::string &line,
                           const std::map<std::string, double> &rates) {
  std::pair<std::string, double> pair =
      std::make_pair(getDate(line, "|"), getVal(line, "|"));
  std::map<std::string, double>::const_iterator it;
  double res;
  for (it = rates.begin(); it != rates.end() && pair.first > it->first; ++it) {
  }
  if (it == rates.end() || (pair.first < it->first && it != rates.begin()))
    res = (--it)->second;
  else if (pair.first == it->first)
    res = it->second;
  else {
    std::cerr << "Error: the date given precedes the information in the data "
                 "file => \""
              << line << "\"" << std::endl;
    return;
  }
  res *= pair.second;
  std::cout.precision(10);
  std::cout << pair.first << " => " << pair.second << " = " << res << std::endl;
}

void BitcoinExchange::processStats() const {
  if (!fileIsValid("data.csv"))
    throw;
  std::ifstream input(this->getInputFile());
  if (!input)
    throw std::runtime_error("could not open input file");
  std::string line;
  std::getline(input, line);
  if (line != "date | value") {
    input.close();
    throw std::runtime_error("wrong header in input file => \"" + line + "\"");
  }
  while (std::getline(input, line)) {
    if (!statFormatIsValid(line)) {
      std::cerr << "Error: bad format in input file => \"" + line + "\""
                << std::endl;
      continue;
    }
    processOneStat(line, getRates());
  }
  input.close();
}
