/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:51:15 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/04 21:51:19 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <stdexcept>

class RPN {
public:
  explicit RPN(const std::string &expr);
  virtual ~RPN();
  double getResult() const;

private:
  const std::string _expr;
  RPN();
  RPN(const RPN &src);
  RPN &operator=(const RPN &rhs);
};

std::ostream &operator<<(std::ostream &o, const RPN &rhs);

#endif
