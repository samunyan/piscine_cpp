/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/06 16:05:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

namespace utils {
template <typename InputIt, typename OutputIt, typename UnaryOperation>
void transform(InputIt begin1, InputIt end1, OutputIt begin2,
               UnaryOperation unary_op) {
  while (begin1 != end1)
    *begin2++ = unary_op(*begin1++);
}
template <class T> std::back_insert_iterator<T> back_inserter(T &c) {
  return std::back_insert_iterator<T>(c);
}

template <typename U> static void swap(U &a, U &b) {
  U tmp = a;
  a = b;
  b = tmp;
}

template <typename I> static void sortEachPair(I begin, I end) {
  for (I it = begin; it != end; ++it) {
    if (it->first < it->second)
      swap(it->first, it->second);
  }
}

template <typename OutputIt, typename InputIt>
void makePairs(InputIt begin1, InputIt end1, OutputIt begin2) {
  for (; begin1 != end1; ++begin2) {
    begin2->first = *begin1++;
    begin2->second = *begin1++;
  }
}

template <typename InputIt, typename OutputIt>
OutputIt copy(InputIt begin, InputIt end, OutputIt dst) {
  for (; begin != end; ++begin, ++dst)
    *dst = *begin;
  return dst;
}

template <typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt merge(InputIt1 begin1, InputIt1 end1, InputIt2 begin2, InputIt2 last2,
               OutputIt dst) {
  for (; begin1 != end1; ++dst) {
    if (begin2 == last2)
      return utils::copy(begin1, end1, dst);
    if (*begin2 < *begin1) {
      *dst = *begin2;
      ++begin2;
    } else {
      *dst = *begin1;
      ++begin1;
    }
  }
  return utils::copy(begin2, last2, dst);
}

int getFirst(const std::pair<int, int> &pair);
int getSecond(const std::pair<int, int> &pair);
bool strIsNumber(const std::string &str);
bool numberIsValid(long n);
}

#endif
