/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:16:31 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/25 01:16:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

class Pair {
public:
  Pair();
  Pair(int x, int y);
  Pair(const Pair &src);
  Pair &operator=(const Pair &rhs);
  virtual ~Pair();
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);

private:
  int _x;
  int _y;
};

std::ostream &operator<<(std::ostream &o, const Pair &rhs);

#endif
