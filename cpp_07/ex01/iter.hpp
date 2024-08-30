/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:31:24 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/24 12:31:25 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "Pair.hpp"
#include <iostream>

template <typename T, typename F> void iter(T *arr, size_t len, F f) {
  for (size_t i(0); i < len; ++i) {
    f(arr[i]);
  }
}

template <typename T> void print(const T &a) { std::cout << a << ' '; }

template <typename T> void add(T &a) { a++; }

template <> void add<Pair>(Pair &a) {
  a.setX(a.getX() + 1);
  a.setY(a.getY() + 1);
}

#endif
