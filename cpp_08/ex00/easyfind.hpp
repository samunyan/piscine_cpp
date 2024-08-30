/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 02:12:01 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/26 02:12:01 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T> typename T::const_iterator easyfind(T &ct, int val) {
  typename T::const_iterator it;
  it = std::find(ct.begin(), ct.end(), val);
  if (it == ct.end())
    throw std::runtime_error("not found");
  return it;
}

#endif
