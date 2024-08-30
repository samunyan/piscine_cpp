/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:31 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:20:32 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
  std::string str("HI THIS IS BRAIN");
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << &str << std::endl
            << stringPTR << std::endl
            << &stringREF << std::endl;
  std::cout << str << std::endl
            << *stringPTR << std::endl
            << stringREF << std::endl;
  return 0;
}
