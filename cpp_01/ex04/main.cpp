/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:20:59 by samunyan          #+#    #+#             */
/*   Updated: 2023/03/28 16:21:00 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static bool isValidInf(const std::ifstream &inf, const std::string &name) {

  if (!inf) {
    std::cerr << "Error: " + name + " could not be opened for reading"
              << std::endl;
    return false;
  }
  return true;
}

static bool isValidOutf(const std::ofstream &outf, const std::string &name) {

  if (!outf) {
    std::cerr << "Error: " << name + " could not be opened for writing"
              << std::endl;
    return false;
  }
  return true;
}

static void replace(std::ifstream &inf, std::ofstream &outf,
                    const std::string &needle, const std::string &replace) {

  std::string haystack;
  std::string line;
  std::string::size_type i;

  while (inf) {

    line.clear();
    getline(inf, line);
    haystack += line;
    if (!inf.eof())
      haystack += '\n';

    if (!needle.empty()) {
      while (true) {
        i = haystack.find(needle);
        if (i == std::string::npos)
          break;
        outf << haystack.substr(0, i) << replace;
        haystack.erase(0, i + needle.length());
      }
    }
  }
  outf << haystack;
}

int main(int ac, char *av[]) {

  if (ac != 4) {
    std::cerr << "Error: wrong number of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  const std::string nameInf(av[1]);
  std::ifstream inf(nameInf.c_str());
  if (!isValidInf(inf, nameInf))
    return EXIT_FAILURE;

  const std::string nameOutf(nameInf + ".replace");
  std::ofstream outf(nameOutf.c_str());
  if (!isValidOutf(outf, nameOutf)) {
    inf.close();
    return EXIT_FAILURE;
  }

  replace(inf, outf, av[2], av[3]);

  inf.close();
  outf.close();
  return EXIT_SUCCESS;
}
