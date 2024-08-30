/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:20:33 by samunyan          #+#    #+#             */
/*   Updated: 2023/10/15 20:56:11 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {

  Data *obj1 = new Data;
  obj1->n = 42;
  obj1->b = true;

  uintptr_t ptr = Serializer::serialize(obj1);
  Data *obj2 = Serializer::deserialize(ptr);

  std::cout << std::boolalpha << (obj1 == obj2) << std::endl;
  std::cout << std::boolalpha << (obj1->n == obj2->n) << std::endl;
  std::cout << std::boolalpha << (obj1->b == obj2->b) << std::endl;

  delete obj2;
  return 0;
}