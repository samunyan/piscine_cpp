/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:47 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:48 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>

template <typename T> class Array {
public:
  Array();
  Array(unsigned int n);
  Array(const Array &src);
  Array &operator=(const Array &rhs);
  virtual ~Array();
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
  unsigned int size() const;

private:
  unsigned int _length;
  T *_array;
};

template <typename T> void fillArray(Array<T> &arr);

#endif

#include "Array.tpp"
