/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:51 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:52 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return (Account::_nbAccounts); }

int Account::getTotalAmount() { return (Account::_totalAmount); }

int Account::getNbDeposits() { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals() { return (Account::_totalNbWithdrawals); }

void Account::displayAccountsInfos() {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts
            << ";total:" << Account::_totalAmount
            << ";deposits:" << Account::_totalNbDeposits
            << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(Account::_nbAccounts), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0) {
  Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;
  Account::_displayTimestamp();
  std::cout << "index" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account() {
  Account::_nbAccounts--;
  Account::_displayTimestamp();
  std::cout << "index" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();
  std::cout << "index" << this->_accountIndex << ";p_amount:" << this->_amount;
  this->_amount += deposit;
  Account::_totalAmount += deposit;
  this->_nbDeposits++;
  Account::_totalNbDeposits++;
  std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << "index" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";
  if (this->_amount < withdrawal) {
    std::cout << "refused" << std::endl;
    return (false);
  }
  this->_amount -= withdrawal;
  Account::_totalAmount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalNbWithdrawals++;
  std::cout << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount() const { return (this->_amount); }

void Account::displayStatus() const {
  Account::_displayTimestamp();
  std::cout << "index" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t now = time(NULL);
  std::tm *local = localtime(&now);
  std::cout << "[" << 1900 + local->tm_year << std::setfill('0') << std::setw(2)
            << local->tm_mon << std::setfill('0') << std::setw(2)
            << local->tm_mday << "_" << std::setfill('0') << std::setw(2)
            << local->tm_hour << std::setfill('0') << std::setw(2)
            << local->tm_min << std::setfill('0') << std::setw(2)
            << local->tm_sec << "] ";
}

Account::Account() {}
