/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:53:57 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/06 12:53:57 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <> std::string PmergeMe<std::vector<int> >::getContainerType() const {
  return "vector";
}

template <> std::string PmergeMe<std::deque<int> >::getContainerType() const {
  return "deque";
}

template <> void PmergeMe<std::vector<int> >::sort() {
  std::clock_t start = std::clock();

  if (_data.size() < 2) {
    _duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
    return;
  }

  if (_data.size() % 2 != 0) {
    _last = _data.back();
    _data.pop_back();
  }

  std::vector<std::pair<int, int> > pairs(_data.size() / 2);
  utils::makePairs(_data.begin(), _data.end(), pairs.begin());
  utils::sortEachPair(pairs.begin(), pairs.end());
  _mergeSort(pairs);

  _data.clear();
  std::vector<int> pend;
  utils::transform(pairs.begin(), pairs.end(), utils::back_inserter(_data),
                   utils::getFirst);
  utils::transform(pairs.begin(), pairs.end(), utils::back_inserter(pend),
                   utils::getSecond);

  _data.insert(_data.begin(), pend.front());
  pend.erase(pend.begin());

  if (_last != sentinel)
    pend.push_back(_last);

  while (!pend.empty()) {
    int val = pend.front();
    _data.insert(_data.begin() + _binarySearch(val), val);
    pend.erase(pend.begin());
  }

  _duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <> void PmergeMe<std::deque<int> >::sort() {
  std::clock_t start = std::clock();
  if (_data.size() < 2) {
    _duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
    return;
  }

  if (_data.size() % 2 != 0) {
    _last = _data.back();
    _data.pop_back();
  }

  std::deque<std::pair<int, int> > pairs(_data.size() / 2);
  utils::makePairs(_data.begin(), _data.end(), pairs.begin());
  utils::sortEachPair(pairs.begin(), pairs.end());
  _mergeSort(pairs);

  _data.clear();
  std::deque<int> pend;
  utils::transform(pairs.begin(), pairs.end(), utils::back_inserter(_data),
                   utils::getFirst);
  utils::transform(pairs.begin(), pairs.end(), utils::back_inserter(pend),
                   utils::getSecond);

  _data.push_front(pend.front());
  pend.pop_front();

  if (_last != sentinel)
    pend.push_back(_last);

  while (!pend.empty()) {
    int val = pend.front();
    _data.insert(_data.begin() + _binarySearch(val), val);
    pend.pop_front();
  }

  _duration = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}
