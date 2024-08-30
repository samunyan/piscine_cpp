/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:39:20 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/06 16:11:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:17:25 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/05 22:17:42 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "utils.hpp"
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <vector>

template <typename T> class PmergeMe {
public:
  PmergeMe();
  virtual ~PmergeMe();
  void setData(char *av[]);
  void printData() const;
  std::string getContainerType() const;
  void benchmarkMessage() const;
  void sort();
  typedef enum { sentinel = -1 } t_enums;

private:
  T _data;
  int _last;
  double _duration;
  void _mergeSort(std::vector<std::pair<int, int> > &pairs);
  void _mergeSort(std::deque<std::pair<int, int> > &pairs);
  size_t _binarySearch(int n);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &rhs);
};

#endif

#include "PmergeMe.tpp"
