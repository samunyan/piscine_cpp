/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:06:09 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:10 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

static char ft_toupper(const char c) {
  return (static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
}

int main(int ac, char *av[]) {
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

  for (int i = 1; i < ac; ++i) {
    const std::string &s = av[i];
    for (size_t j = 0; j < s.length(); ++j)
      std::cout << ft_toupper(s[j]);
  }

  std::cout << std::endl;

  return (0);
}
