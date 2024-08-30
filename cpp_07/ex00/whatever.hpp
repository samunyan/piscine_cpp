/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:05:27 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 11:05:29 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "Pair.hpp"
#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> const T &min(const T &a, const T &b) {
  return ((a < b) ? a : b);
}

template <typename T> const T &max(const T &a, const T &b) {
  return ((a > b) ? a : b);
}

template <> const Pair &min(const Pair &a, const Pair &b) {
  return ((a.getX() < b.getX() && a.getY() < b.getY()) ? a : b);
}

template <> const Pair &max(const Pair &a, const Pair &b) {
  return ((a.getX() > b.getX() && a.getY() > b.getY()) ? a : b);
}

#endif
