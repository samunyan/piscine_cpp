/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:51:49 by samunyan          #+#    #+#             */
/*   Updated: 2023/04/12 18:51:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const int nb(3);
  AAnimal *animals[nb];
  for (int i(0); i < nb / 2; ++i) {
    animals[i] = new Cat();
  }
  for (int i(nb / 2); i < nb; ++i) {
    animals[i] = new Dog();
  }
  for (int i(0); i < nb; ++i) {
    delete animals[i];
  }

  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();
  delete j;
  delete i;

  Cat *cat(new Cat());
  Cat *copy(new Cat(*cat));
  delete cat;
  std::cout << *copy->getBrain();
  delete copy;

  // AAnimal abstract;
  //  compile error: variable type 'AAnimal' is an abstract class

  return 0;
}