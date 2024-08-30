/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:06 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/06 16:05:06 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int utils::getFirst(const std::pair<int, int> &pair) { return pair.first; }

int utils::getSecond(const std::pair<int, int> &pair) { return pair.second; }

bool utils::strIsNumber(const std::string &str) {
  return str.find_first_not_of("0123456789");
}

bool utils::numberIsValid(long n) {
  return (0 <= n && n <= std::numeric_limits<int>::max());
}
