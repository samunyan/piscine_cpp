/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:17:40 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/15 14:17:43 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

class ScalarConverter {
public:
  typedef enum e_type { CHAR, INT, FLOAT, DOUBLE } t_type;
  static void convert(const std::string &s);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  virtual ~ScalarConverter();
};

#endif
