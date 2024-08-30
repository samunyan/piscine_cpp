/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:07 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:21:08 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);

private:
  void debug();
  void info();
  void warning();
  void error();
};

typedef struct s_dispatch {
  std::string level;
  void (Harl::*f)();
} t_dispatch;

#endif
