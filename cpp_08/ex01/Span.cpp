/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:13:29 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/26 23:13:34 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int maxLen) : _maxLen(maxLen) {}

Span::Span(const Span &src) : _maxLen(src._maxLen), _mSet(src._mSet) {}

Span::~Span() {}

const std::multiset<int> &Span::getSet() const { return this->_mSet; }

void Span::addNumber(int i) {
  if (this->_mSet.size() == this->_maxLen)
    throw SpanIsFullException();
  this->_mSet.insert(i);
}

static int getRandomNumber() { return (std::rand() % 10000); }

void Span::addRange(unsigned int count) {
  if (this->_mSet.size() + count > this->_maxLen)
    throw SpanIsFullException();
  std::vector<int> vec(count);
  std::generate(vec.begin(), vec.end(), getRandomNumber);
  this->_mSet.insert(vec.begin(), vec.end());
}

unsigned int Span::shortestSpan() const {
  if (this->_mSet.size() < 2)
    throw NoSpanException();
  unsigned int minDiff = this->longestSpan();
  std::multiset<int>::const_iterator itFirst;
  std::multiset<int>::const_iterator itSecond;
  for (itFirst = this->_mSet.begin(), itSecond = ++this->_mSet.begin();
       itSecond != this->_mSet.end(); ++itFirst, ++itSecond) {
    unsigned int diff = *itSecond - *itFirst;
    minDiff = (diff < minDiff) ? diff : minDiff;
  }
  return minDiff;
}

unsigned int Span::longestSpan() const {
  if (this->_mSet.size() < 2)
    throw NoSpanException();
  return (*(--this->_mSet.end()) - *(this->_mSet.begin()));
}

Span::SpanIsFullException::SpanIsFullException()
    : std::runtime_error("span is full") {}

Span::NoSpanException::NoSpanException()
    : std::runtime_error("no span can be found") {}

std::ostream &operator<<(std::ostream &o, const Span &rhs) {
  std::multiset<int>::const_iterator it;
  for (it = rhs.getSet().begin(); it != rhs.getSet().end(); ++it)
    o << *it << ' ';
  return o;
}
