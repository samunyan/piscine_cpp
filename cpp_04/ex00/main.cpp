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
#include "WrongCat.hpp"

int main() {
  const Animal *meta(new Animal());
  const Animal *dog(new Dog());
  const Animal *cat(new Cat());
  std::cout << std::endl;

  std::cout << *meta;
  meta->makeSound();
  std::cout << std::endl;
  std::cout << *dog;
  dog->makeSound();
  std::cout << std::endl;
  std::cout << *cat;
  cat->makeSound();
  std::cout << std::endl;

  delete meta;
  delete dog;
  delete cat;
  std::cout << std::endl;

  const WrongAnimal *wrongMeta(new WrongAnimal());
  const WrongAnimal *wrongCat(new WrongCat());
  std::cout << std::endl;

  std::cout << *wrongMeta;
  wrongMeta->makeSound();
  std::cout << std::endl;

  std::cout << *wrongCat;
  wrongCat->makeSound();
  std::cout << std::endl;

  delete wrongMeta;
  delete wrongCat;

  return 0;
}