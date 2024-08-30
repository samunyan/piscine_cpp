/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:13:29 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/26 23:13:34 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
#include <stdexcept>
#include <vector>

class Span {
public:
  explicit Span(unsigned int maxLen);
  Span(const Span &src);
  virtual ~Span();
  const std::multiset<int> &getSet() const;
  void addNumber(int number);
  void addRange(unsigned int count);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  class SpanIsFullException : public std::runtime_error {
  public:
    SpanIsFullException();
  };
  class NoSpanException : public std::runtime_error {
  public:
    NoSpanException();
  };

private:
  const unsigned int _maxLen;
  std::multiset<int> _mSet;
  Span();
  Span &operator=(const Span &rhs);
};

std::ostream &operator<<(std::ostream &o, const Span &rhs);

#endif
