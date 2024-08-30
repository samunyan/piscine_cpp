/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:22:27 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/05 08:35:17 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template <typename T> PmergeMe<T>::PmergeMe() : _last(sentinel), _duration(0) {}

template <typename T> PmergeMe<T>::~PmergeMe() {}

template <typename T> void PmergeMe<T>::setData(char *av[]) {
  size_t i(0);
  long n;
  while (av[i]) {
    if (!utils::strIsNumber(av[i]))
      throw(std::runtime_error("invalid number : " + std::string(av[i])));
    std::stringstream ss(av[i]);
    ss >> n;
    if (!utils::numberIsValid(n))
      throw(std::runtime_error("invalid number: " + std::string(av[i])));
    this->_data.push_back(static_cast<int>(n));
    i++;
  }
}

template <typename T> void PmergeMe<T>::printData() const {
  typename T::const_iterator it = _data.begin();
  for (; it != _data.end(); ++it)
    std::cout << *it << ' ';
}

template <typename T> void PmergeMe<T>::benchmarkMessage() const {
  std::cout << "Time to process a range of " << _data.size()
            << " elements with std::" << this->getContainerType() << " : "
            << std::fixed << _duration << " us" << std::endl;
}

template <typename T>
void PmergeMe<T>::_mergeSort(std::vector<std::pair<int, int> > &pairs) {
  if (pairs.size() <= 1)
    return;
  std::vector<std::pair<int, int> >::iterator mid = pairs.begin();
  std::advance(mid, pairs.size() / 2);
  std::vector<std::pair<int, int> > lo(pairs.begin(), mid);
  std::vector<std::pair<int, int> > hi(mid, pairs.end());
  _mergeSort(lo);
  _mergeSort(hi);
  utils::merge(lo.begin(), lo.end(), hi.begin(), hi.end(), pairs.begin());
}

template <typename T>
void PmergeMe<T>::_mergeSort(std::deque<std::pair<int, int> > &pairs) {
  if (pairs.size() <= 1)
    return;
  std::deque<std::pair<int, int> >::iterator mid = pairs.begin();
  std::advance(mid, pairs.size() / 2);
  std::deque<std::pair<int, int> > lo(pairs.begin(), mid);
  std::deque<std::pair<int, int> > hi(mid, pairs.end());
  _mergeSort(lo);
  _mergeSort(hi);
  utils::merge(lo.begin(), lo.end(), hi.begin(), hi.end(), pairs.begin());
}

template <typename T> size_t PmergeMe<T>::_binarySearch(int n) {
  ssize_t lo = 0;
  ssize_t hi = _data.size() - 1;
  while (lo <= hi) {
    ssize_t mid = (lo + hi) / 2;
    if (n == _data[mid])
      return mid;
    if (n < _data[mid])
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return lo;
}

#endif
