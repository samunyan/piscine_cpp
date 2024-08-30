/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:14:36 by samunyan          #+#    #+#             */
/*   Updated: 2023/11/02 15:14:36 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
  try {
    if (ac < 2)
      throw std::runtime_error("usage: ./PmergeMe <positive integer sequence>");

    PmergeMe<std::vector<int> > vector;
    vector.setData(&av[1]);
    std::cout << "Before:\t";
    vector.printData();
    vector.sort();
    std::cout << std::endl;

    PmergeMe<std::deque<int> > deque;
    deque.setData(&av[1]);
    deque.sort();
    std::cout << "After:\t";
    deque.printData();
    std::cout << std::endl;

    vector.benchmarkMessage();
    deque.benchmarkMessage();

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
