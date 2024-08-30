/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:21:09 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:21:10 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl test;

  test.complain("DEBUG");
  test.complain("INFO");
  test.complain("WARNING");
  test.complain("ERROR");
  test.complain("hello");

  return 0;
}
